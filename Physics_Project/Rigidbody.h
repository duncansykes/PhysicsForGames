#pragma once
#include <glm/glm.hpp>
#include "PhysicsObject.h"

class Rigidbody : public PhysicsObject
{
public:

	Rigidbody(ShapeType a_shapeID, mathfs::Vector2 a_position, mathfs::Vector2 a_velocity, float a_rotation, float a_mass);
	~Rigidbody();

	virtual void FixedUpdate(mathfs::Vector2 a_gravity, float a_timeStep);
	virtual void Debug() {};

	void Rigidbody::ApplyForce(mathfs::Vector2 a_force);


	void ApplyForceToOther(Rigidbody* a_otherActor, mathfs::Vector2 a_force);

	virtual bool CheckCollision(PhysicsObject* pOther) = 0;

	mathfs::Vector2 GetPosition() { return m_position; }
	mathfs::Vector2 GetVelocity() { return m_velocity; }

	float GetMass() { return m_mass; }
	float GetRotation() { return m_rotation; }

	float getMoment() { return m_moment; }

	void Rigidbody::ResolveCollision(Rigidbody* a_otherActor);

protected:
	mathfs::Vector2 m_position;
	mathfs::Vector2 m_velocity;

	float m_orientation;
	float m_angularVelocity;
	float m_moment;
	float m_mass;
	float m_rotation;
};
