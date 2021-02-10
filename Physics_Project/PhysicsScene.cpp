#include "PhysicsScene.h"
#include "PhysicsObject.h"
#include "Rigidbody.h"
#include "Sphere.h"
#include "Plane.h"
#include "Box.h"

#include <iostream>
#include <list>

typedef bool (*fn)(PhysicsObject*, PhysicsObject*);

static fn collisionFunctionArray[] =
{
	PhysicsScene::Plane2Sphere, PhysicsScene::Plane2Sphere, PhysicsScene::Plane2Box,
	PhysicsScene::Sphere2Plane, PhysicsScene::Sphere2Sphere, PhysicsScene::Sphere2Box,
	PhysicsScene::Box2Plane, PhysicsScene::Box2Sphere, PhysicsScene::Box2Box
};

PhysicsScene::PhysicsScene() : m_timeStep(0.01f), m_gravity(mathfs::Vector2(0, 0))
{
}

PhysicsScene::~PhysicsScene()
{
	for (auto pActor : m_actors)
	{
		
		delete pActor;
	}
}


void PhysicsScene::ForceDelete()
{

	for (auto p : m_actors)
	{		
		if (p->getShapeID() == SPHERE)
		{
			auto it = std::find(m_actors.begin(), m_actors.end(),p);
			m_actors.erase(it);
			return;
		}

	}

}

void PhysicsScene::addActor(PhysicsObject* a_actor)
{
	m_actors.push_back(a_actor);
}

void PhysicsScene::removeActor(PhysicsObject* a_actor)
{
	auto it = std::find(m_actors.begin(), m_actors.end(),
		a_actor);

	if (it != m_actors.end())
	{
		m_actors.erase(it);
	}
}

void PhysicsScene::update(float deltaTime)
{
	static float accumulatedTime = 0.f;
	accumulatedTime += deltaTime;

	while (accumulatedTime >= m_timeStep)
	{
		for (auto pActor : m_actors)
		{
			pActor->FixedUpdate(m_gravity, m_timeStep);
		}

		accumulatedTime -= m_timeStep;

		CheckForCollision();
	}
}

void PhysicsScene::draw()
{
	for (auto pActor : m_actors)
	{
		pActor->MakeGizmo();
	}
}

void PhysicsScene::DebugScene()
{
	int count = 0;
	for (auto pActor : m_actors)
	{
		std::cout << count << " : ";
		pActor->Debug();
		count++;
	}
}

void PhysicsScene::CheckForCollision()
{
	int actorCount = m_actors.size();
	//

	for (int outer = 0; outer < actorCount; outer++)
	{
		for (int inner = outer + 1; inner < actorCount; inner++)
		{
			PhysicsObject* objOuter = m_actors[outer];
			PhysicsObject* objInner = m_actors[inner];

			int shapeID_out = objOuter->getShapeID();
			int shapeID_inner = objInner->getShapeID();

			int functionIdx = (shapeID_out * SHAPE_COUNT) + shapeID_inner;
			fn collisionFunctPointer = collisionFunctionArray[functionIdx];
			if (collisionFunctPointer != nullptr)
			{
				
				collisionFunctPointer(objOuter, objInner);
				
			}
			
		}
	}
}

bool PhysicsScene::Plane2Box(PhysicsObject* obj1, PhysicsObject* obj2)
{
	Plane* plane = dynamic_cast<Plane*>(obj1);
	Box* box = dynamic_cast<Box*>(obj2);


	// If successful, we test for collision
	if (box != nullptr && plane != nullptr)
	{
		
		int numContacts = 0;
		mathfs::Vector2 contact(0, 0);
		float contactV = 0;
		// Get a representation point on the plane
		mathfs::Vector2 planeOrigin = plane->GetNormal() * plane->GetDistance();

		// Check all corners for a collision
		for (float x = -box->GetExtents().x; x < box->GetWidth(); x+=box->GetWidth())
		{
		
			for (float y = -box->GetExtents().y; y < box->GetHeight(); y += box->GetHeight())
			{
				// Get the position of the corners in world space
				mathfs::Vector2 p = box->GetPosition() + box->GetLocalX() * x + box->GetLocalY() * y;
				float distFromPlane = mathfs::extra::dot(p - planeOrigin, plane->GetNormal());

				// This is the total velocity of the points in world space
				mathfs::Vector2 displacement = box->GetLocalX() * x + box->GetLocalY() * y;
				mathfs::Vector2 pointVelocity = box->GetVelocity() + box->GetAngVelocity() *
					glm::vec2(-displacement.y, displacement.x);

				// This is the amount of point velocity into the plane
				float velocityIntoPlane = mathfs::extra::dot(pointVelocity, plane->GetNormal());

				// Moving further in, we need to resolve the collision
				if (distFromPlane < 0 && velocityIntoPlane <= 0)
				{

					numContacts++;
					contact += p;
					contactV += velocityIntoPlane;


				}

			}
		}

		if (numContacts > 0) {
			plane->ResolveCollision(box, contact / (float)numContacts);
			return true;
		}

	}

	
	return false;
}

bool PhysicsScene::Plane2Plane(PhysicsObject*, PhysicsObject*)
{
	return false;
}

bool PhysicsScene::Plane2Sphere(PhysicsObject* objPlane, PhysicsObject* objSphere)
{
	return Sphere2Plane(objSphere, objPlane);
}

bool PhysicsScene::Sphere2Plane(PhysicsObject* objSphere, PhysicsObject* objPlane)
{
	Sphere* sphere = dynamic_cast<Sphere*>(objSphere);
	Plane* plane = dynamic_cast<Plane*>(objPlane);

	// If these have a value, continue below
	if (sphere != nullptr && plane != nullptr)
	{
		mathfs::Vector2 CollisionNormal = plane->GetNormal();

		float sphereToPlane = mathfs::extra::dot(sphere->GetPosition(), CollisionNormal - plane->GetDistance());

		float intersection = sphere->GetRadius() - sphereToPlane; 

		float velocityOutOfPlane  = mathfs::extra::dot(sphere->GetVelocity(), CollisionNormal);

		if (intersection > 0 && velocityOutOfPlane < 0)
		{
			
			mathfs::Vector2 contact = sphere->GetPosition() + (CollisionNormal * -sphere->GetRadius());
			plane->ResolveCollision(sphere, contact);
			return true;
		}
	}

	return false;
}

bool PhysicsScene::Sphere2Sphere(PhysicsObject* obj1, PhysicsObject* obj2)
{
	Sphere* sphere1 = dynamic_cast<Sphere*>(obj1);
	Sphere* sphere2 = dynamic_cast<Sphere*>(obj2);


	if (sphere1 != nullptr && sphere2 != nullptr)
	{

		float distance = mathfs::extra::distance(sphere1->GetPosition(), sphere2->GetPosition());
		float penetration = sphere1->GetRadius() + sphere2->GetRadius() - distance;

		if (penetration > 0)
		{

			sphere1->ResolveCollision(sphere2,  (sphere1->GetPosition()+ sphere2->GetPosition()*0.5f));
			return true;
		}
	}

	return false;
}

bool PhysicsScene::Sphere2Box(PhysicsObject* obj1, PhysicsObject* obj2)
{
	Sphere* sphere = dynamic_cast<Sphere*>(obj1);
	Box* box = dynamic_cast<Box*>(obj2);

	if (box != nullptr && sphere != nullptr) {
		mathfs::Vector2 circlePosWorld = sphere->GetPosition() - box->GetPosition();
		mathfs::Vector2 circlePosBox = mathfs::Vector2(mathfs::extra::dot(circlePosWorld, box->GetLocalX()),
			mathfs::extra::dot(circlePosWorld, box->GetLocalY()));

		mathfs::Vector2 closestPointOnTheBox = circlePosBox;
		mathfs::Vector2 extents = box->GetExtents();
		if (closestPointOnTheBox.x < -extents.x)  closestPointOnTheBox.x = -extents.x;
		if (closestPointOnTheBox.x >  extents.x)  closestPointOnTheBox.x =  extents.x;
		if (closestPointOnTheBox.y < -extents.y)  closestPointOnTheBox.y = -extents.y;
		if (closestPointOnTheBox.y >  extents.y)  closestPointOnTheBox.y =  extents.y;

		glm::vec2 closestPointOnBoxWorld = box->GetPosition().vectorToglm() + closestPointOnTheBox.x * box->GetLocalX().vectorToglm()
																	+ closestPointOnTheBox.y * box->GetLocalY().vectorToglm();
		glm::vec2 circleToBox = sphere->GetPosition().vectorToglm() - closestPointOnBoxWorld;
		if (glm::length(circleToBox) < sphere->GetRadius())
		{
			mathfs::Vector2 direction = mathfs::Vector2(circleToBox.x, circleToBox.y).Normalize();
			mathfs::Vector2 contact = mathfs::Vector2(closestPointOnBoxWorld.x, closestPointOnBoxWorld.y);
			box->ResolveCollision(sphere, contact, &direction);
		}
	}
	return false;
}

bool PhysicsScene::Box2Plane(PhysicsObject* obj1, PhysicsObject* obj2)
{
	
	Plane2Box(obj2, obj1);


	return false;
}
bool PhysicsScene::Box2Box(PhysicsObject* obj1, PhysicsObject* obj2)
{
	Box* box1 = dynamic_cast<Box*>(obj1);
	Box* box2 = dynamic_cast<Box*>(obj2);

	if (box1 != nullptr && box2 != nullptr) {

		mathfs::Vector2 morn(0, 0);
		mathfs::Vector2 contact(0, 0);
		float pen = 0;
		int numCOntacts = 0;
		box1->CheckBoxCorners(*box2, contact, numCOntacts, pen, morn);
		if (box2->CheckBoxCorners(*box1, contact, numCOntacts, pen, morn))
		{
			morn = -morn;
		}
		if (pen > 0)
		{
			box1->ResolveCollision(box2, contact / (float)(numCOntacts), &morn);
		}

	}

	return false;
}

bool PhysicsScene::Box2Sphere(PhysicsObject* obj1, PhysicsObject* obj2)
{
	Sphere2Box(obj2, obj1);
	return false;
}
