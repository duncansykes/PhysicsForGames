#pragma once
#include "PhysicsObject.h"
#include "Rigidbody.h"
#include "PhysicsScene.h"
#include <Gizmos.h>
#include <iostream>
#include <glm/glm.hpp>

class Spring : public PhysicsObject
{
public:
	Spring(Rigidbody* a_actor1, Rigidbody* a_actor2, float a_damping, float a_springCoefficient, float a_restLength = 0,
		glm::vec2 a_contact1 = glm::vec2(0), glm::vec2 a_contact2 = glm::vec2(0));
	~Spring();

	virtual void FixedUpdate(glm::vec2 a_gravity, float a_timeStep);
	virtual void Debug() {};
	virtual void MakeGizmo();
	virtual void ResetPosition() {};

	virtual bool IsInside(glm::vec2 a_point) { return false; }

	glm::vec2 GetContact1() { return m_actor1 ? m_actor1->ToWorld(m_contact1) : m_contact1; }
	glm::vec2 GetContact2() { return m_actor2 ? m_actor2->ToWorld(m_contact2) : m_contact2; }

protected:
	Rigidbody* m_actor1;
	Rigidbody* m_actor2;

	glm::vec2 m_contact1;
	glm::vec2 m_contact2;

	float m_damping;
	float m_restLength;
	float m_springCoefficient;
};
