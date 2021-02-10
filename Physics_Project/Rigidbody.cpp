#include "Rigidbody.h"

Rigidbody::Rigidbody(ShapeType a_shapeID, mathfs::Vector2 a_position, mathfs::Vector2 a_velocity, float a_rotation, float a_mass) : PhysicsObject(a_shapeID)
{
	m_position = a_position;
	m_velocity = a_velocity;
	m_rotation = a_rotation;
	m_mass = a_mass;
	m_angularVelocity = 0;
	m_isKinematic = false;
	m_elasticicty = 0.8;

}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::FixedUpdate(mathfs::Vector2 a_gravity, float a_timeStep)
{
	ApplyForce(a_gravity * GetMass() * a_timeStep, mathfs::Vector2(0,0));
	m_position += GetVelocity() * a_timeStep;

	m_rotation += m_angularVelocity * a_timeStep;
}

void Rigidbody::ApplyForce(mathfs::Vector2 a_force, mathfs::Vector2 a_pos)
{
	m_velocity += a_force / GetMass();
	m_angularVelocity += (a_force.y * a_pos.x - a_force.x * a_pos.y) / getMoment();
}






void Rigidbody::ResolveCollision(Rigidbody* a_otherActor, mathfs::Vector2 a_contact, mathfs::Vector2* a_collisionNormal)
{
	// Move the vectors between their centers, or use the provided
	// direction of force and make sure it's normalised
	mathfs::Vector2 Normal = (a_collisionNormal ? *a_collisionNormal : a_otherActor->GetPosition() - GetPosition()).Normalize();

	// Get the vector perpendicular to the normal
	mathfs::Vector2 perpendicularCollisionNormal(Normal.y, -Normal.x);

	// These are applied to the radius from axis to the application of force
	float radius1 = mathfs::extra::dot(a_contact - m_position, -perpendicularCollisionNormal);
	float radius2 = mathfs::extra::dot(a_contact - a_otherActor->GetPosition(), perpendicularCollisionNormal);

	// Velocity of the contact point on this object
	float cp_velocity1 = mathfs::extra::dot(m_velocity, Normal) - radius1 * m_angularVelocity;

	// Velocity of the other object contact point
	float cp_velocity2 = mathfs::extra::dot(a_otherActor->GetVelocity(), Normal) + radius2 * a_otherActor->m_angularVelocity;

	if (cp_velocity1 > cp_velocity2) //	They are moving closer... 
	{
		// This will calculate the effective mass at the contact point of each
		// object (How much it will move due to the forces applied).
		float mass1 = 1.f / (1.f / m_mass + (radius1 * radius1) / getMoment());
		float mass2 = 1.f / (1.f / a_otherActor->m_mass + (radius2 * radius2) / a_otherActor->getMoment());

		float elasticity = (m_elasticicty + a_otherActor->getElasicity()) / 2.f;

		glm::vec2 imp = (1.f + elasticity) * mass1 * mass2 / (mass1 + mass2) * (cp_velocity1 - cp_velocity2) * Normal.vectorToglm();

		mathfs::Vector2 impact(imp.x, imp.y);

		ApplyForce(-impact, a_contact - m_position);
		a_otherActor->ApplyForce(impact, a_contact - a_otherActor->GetPosition());

	}


	
}

