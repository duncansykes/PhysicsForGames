#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "Vector2.h"
#include "Vector4.h"


class PhysicsObject;

class PhysicsScene
{
public:

	PhysicsScene();
	~PhysicsScene();

	void ForceDelete();

	void addActor(PhysicsObject* a_actor);
	void removeActor(PhysicsObject* a_actor);

	void update(float deltaTime);
	void draw();
	void DebugScene();

	void setGravity(const mathfs::Vector2 a_gravity) { m_gravity = a_gravity; }
	mathfs::Vector2 GetGravity() { return m_gravity; }

	void setTimeStep(const float a_timeStep) { m_timeStep = a_timeStep; }
	float getTimeStep() { return m_timeStep; }

	void CheckForCollision();

	static bool Plane2Box(PhysicsObject*, PhysicsObject*);
	static bool Plane2Plane(PhysicsObject*, PhysicsObject*);
	static bool Plane2Sphere(PhysicsObject*, PhysicsObject*);
	
	static bool Sphere2Plane(PhysicsObject*, PhysicsObject*);
	static bool Sphere2Sphere(PhysicsObject*, PhysicsObject*);
	static bool Sphere2Box(PhysicsObject*, PhysicsObject*);
	
	static bool Box2Plane(PhysicsObject*, PhysicsObject*);
	static bool Box2Box(PhysicsObject*, PhysicsObject*);
	static bool Box2Sphere(PhysicsObject*, PhysicsObject*);


protected:

	mathfs::Vector2 m_gravity;
	float m_timeStep;

	std::vector<PhysicsObject*> m_actors;
};
