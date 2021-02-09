#include "Rigidbody.h"

Rigidbody::Rigidbody(ShapeType a_shapeID, mathfs::Vector2 a_position, mathfs::Vector2 a_velocity, float a_rotation, float a_mass) : PhysicsObject(a_shapeID)
{
	m_position = a_position;
	m_velocity = a_velocity;
	m_rotation = a_rotation;
	m_mass = a_mass;
}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::FixedUpdate(mathfs::Vector2 a_gravity, float a_timeStep)
{
	ApplyForce(a_gravity * GetMass() * a_timeStep);
	m_position += GetVelocity() * a_timeStep;
}

void Rigidbody::ApplyForce(mathfs::Vector2 a_force)
{
	m_velocity += a_force / GetMass();
}

void Rigidbody::ApplyForceToOther(Rigidbody* a_otherActor, mathfs::Vector2 a_force)
{
	ApplyForce(mathfs::Vector2(-a_force.x, -a_force.y));
	a_otherActor->ApplyForce(a_force);
}

bool Rigidbody::CheckCollision(PhysicsObject* pOther)
{
	return false;
}



void Rigidbody::ResolveCollision(Rigidbody* a_otherActor)
{
	mathfs::Vector2 temp = a_otherActor->GetPosition() - GetPosition();

	mathfs::Vector2 normal = temp.Normalize();
	mathfs::Vector2 relativeVelocity = a_otherActor->GetVelocity() - GetVelocity();

	float elasticity = 1.f;


	float j = mathfs::extra::dot( (relativeVelocity) * -(1.f + elasticity), normal) /
		((1.f / GetMass()) + (1 / a_otherActor->GetMass()));

	mathfs::Vector2 impulse = normal * j;
	ApplyForceToOther(a_otherActor, impulse);

}

