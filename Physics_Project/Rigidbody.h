#pragma once
#include "PhysicsObject.h"
#include <list>
#include <functional>
#include <iostream>

class Rigidbody : public PhysicsObject
{
public:
	Rigidbody(ShapeType a_shapeID, glm::vec2 a_position, glm::vec2 a_velocity, float a_mass, float a_rotation);
	~Rigidbody() {};

	virtual void FixedUpdate(glm::vec2 a_gravity, float a_timeStep);
	virtual void Debug() {};
	void ApplyForce(glm::vec2 a_force, glm::vec2 a_pos);

	void ResolveCollision(Rigidbody* a_otherActor, glm::vec2 a_contact, glm::vec2* a_collisionNormal = nullptr, float a_pen = 0);

	glm::vec2 GetPosition() const { return m_position; }
	glm::vec2 GetVelocity() { return m_velocity; }
	void SetVelocity(glm::vec2 v) { m_velocity = v; }


	float GetMass() { return m_isKinematic ? INT_MAX : m_mass; }
	float GetRotation() { return m_rotation; }

	float GetMoment() { return m_isKinematic ? INT_MAX : m_moment; }
	float GetAngularVelocity() { return m_angularVelocity; }

	glm::vec2 SetPosition(glm::vec2 a_newPos) { return m_position = a_newPos; }
	float SetRotation(float a_rotate) { return m_rotation = a_rotate; }

	float GetLinearDrag() { return m_linearDrag; }
	float GetAngularDrag() { return m_angularDrag; }

	glm::vec2 ToWorld(glm::vec2 a_localPos);

	std::function<void(PhysicsObject*)> m_collisionCallback;

	void TriggerEnter(PhysicsObject* a_otherActor);
	std::function<void(PhysicsObject*)> triggerEnter;
	std::function<void(PhysicsObject*)> triggerExit;
	bool IsTrigger() { return m_isTrigger; }
	bool SetTrigger(bool a_state) { return m_isTrigger = a_state; }
	bool InHole = false;
protected:
	bool m_isTrigger;

	std::list<PhysicsObject*> m_objectInside;
	std::list<PhysicsObject*> m_objectInsideThisFrame;

	glm::vec2 m_position;
	glm::vec2 m_velocity;

	float m_mass;
	float m_rotation;
	float m_angularVelocity;
	float m_moment;

	float m_linearDrag;
	float m_angularDrag;

	// These will store the local x and y axes of the rigidbody based on it's angle of rotation
	glm::vec2 m_localX;
	glm::vec2 m_localY;
};
