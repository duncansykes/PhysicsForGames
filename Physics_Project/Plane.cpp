#include "Plane.h"

#include <Gizmos.h>

Plane::Plane(mathfs::Vector2 a_normal, float a_distance) : PhysicsObject(PLANE)
{
	m_normal = a_normal.Normalize();
	m_distance = a_distance;
	m_color = mathfs::Vector4(0, 1, 0, 1);
	m_isKinematic = false;
	m_elasticicty = 1;
}

Plane::Plane() : PhysicsObject(PLANE)
{
	glm::vec2 normal = glm::normalize(mathfs::Vector2(0, 1).vectorToglm());
	m_normal = mathfs::Vector2(normal.x, normal.y);
	m_distance = 0;
	m_color = mathfs::Vector4(1, 1, 1, 1);
}

Plane::~Plane()
{
}

void Plane::FixedUpdate(mathfs::Vector2 a_gravity, float a_timeStep)
{
}

void Plane::Draw()
{
}

void Plane::Debug()
{
}

void Plane::resetPosition()
{
}

void Plane::MakeGizmo()
{
	float lineSegmentLen = 300.f;
	mathfs::Vector2 centrePoint = GetNormal() * m_distance;

	mathfs::Vector2 parallel(GetNormal().y, -GetNormal().x);
	mathfs::Vector4 colorFade = m_color;
	colorFade.w = 0;
	mathfs::Vector2 start = centrePoint + (parallel * lineSegmentLen);
	mathfs::Vector2 end = centrePoint - (parallel * lineSegmentLen);

	
	glm::vec4 col(m_color.x, m_color.y, m_color.z, m_color.y);
	glm::vec4 colf(colorFade.x, colorFade.y, colorFade.z, colorFade.w);

	//aie::Gizmos::add2DLine(s,e, col);


	aie::Gizmos::add2DTri(start.vectorToglm(), end.vectorToglm(), start.vectorToglm() - GetNormal().vectorToglm() * 10.f, col, col, colf);
	aie::Gizmos::add2DTri(end.vectorToglm(), end.vectorToglm() - GetNormal().vectorToglm() * 10.f, start.vectorToglm() - GetNormal().vectorToglm() * 10.f, col, colf, colf);
}

void Plane::ResolveCollision(Rigidbody* a_otherActor, mathfs::Vector2 a_contact)
{

	// The pos at which we'll apply the force, relative ot the other objects Center of mass
	mathfs::Vector2 localContact = a_contact - a_otherActor->GetPosition();
	mathfs::Vector2 vRel = a_otherActor->GetVelocity() + a_otherActor->GetAngVelocity() * glm::vec2(-localContact.y, localContact.x);
	float velIntoPlane = mathfs::extra::dot(vRel, m_normal);

	// This can be left as a perfect eleasticity for the moment
	float e = 1;

	// This is the perpendicular distance we apply the force at relative 
	// to the center of mass: Torque = F * r
	float r = mathfs::extra::dot(localContact, mathfs::Vector2(m_normal.y, -m_normal.x));

	// This will work out the 'effective mass' - a combination of the moment of inertia
	// and mass, it will tell how much the contact point velocity will the change the force we apply
	float mass0 = 1.f / (1.f / a_otherActor->GetMass() + (r * r) / a_otherActor->getMoment());

	// The plane does not move (Static) so we only use the actor's velocity
	float j = -(1 + e) * velIntoPlane * mass0;
	mathfs::Vector2 force = m_normal * j;
	a_otherActor->ApplyForce(force, a_contact - a_otherActor->GetPosition());



}
