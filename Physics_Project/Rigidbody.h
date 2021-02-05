#pragma once
#include <glm/glm.hpp>
#include "PhysicsObject.h"
class Rigidbody : public PhysicsObject
{

public:

	Rigidbody(ShapeType a_shapeID, glm::vec2 a_position, glm::vec2 a_velocity, float a_rotation, float a_mass);
	~Rigidbody();

	virtual void FixedUpdate(glm::vec2 a_gravity, float a_timeStep);
	virtual void Debug() {};

	void ApplyForce(glm::vec2 a_force);
	void ApplyForceToOther(Rigidbody* a_otherActor, glm::vec2 a_force);

	virtual bool CheckCollision(PhysicsObject* pOther) = 0;

	glm::vec2 GetPosition() { return m_position; }
	glm::vec2 GetVelocity() { return m_velocity; }

	float GetMass() { return m_mass; }
	float GetRotation() { return m_rotation; }

	void ResolveCollision(Rigidbody* a_otherActor);
protected:
	glm::vec2 m_position;
	glm::vec2 m_velocity;

	float m_mass;
	float m_rotation;


};


