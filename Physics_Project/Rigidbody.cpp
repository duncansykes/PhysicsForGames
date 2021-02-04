#include "Rigidbody.h"

Rigidbody::Rigidbody(ShapeType a_shapeID, glm::vec2 a_position, glm::vec2 a_velocity, float a_rotation, float a_mass) : PhysicsObject(a_shapeID)
{
	m_position = a_position;
	m_velocity = a_velocity;
	m_rotation = a_rotation;
	m_mass = a_mass;
}

Rigidbody::~Rigidbody()
{

}

void Rigidbody::FixedUpdate(glm::vec2 a_gravity, float a_timeStep)
{
	ApplyForce(a_gravity * GetMass() * a_timeStep);
	m_position += GetVelocity() * a_timeStep;
}

void Rigidbody::ApplyForce(glm::vec2 a_force)
{
	m_velocity += a_force / GetMass();
}

void Rigidbody::ApplyForceToOther(Rigidbody* a_otherActor, glm::vec2 a_force)
{
	ApplyForce(-a_force);
	a_otherActor->ApplyForce(a_force);
}

bool Rigidbody::CheckCollision(PhysicsObject* pOther)
{

}
