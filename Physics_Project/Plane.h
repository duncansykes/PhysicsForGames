#pragma once
#include "PhysicsObject.h"

// This is a one sided object that extends infinitely along both its edge
// and backwards from its normal direction.

class Plane : public PhysicsObject
{
public:
	Plane(glm::vec2 a_normal, float a_distance);
	Plane();
	~Plane();


	virtual void FixedUpdate(glm::vec2 a_gravity, float a_timeStep);
	virtual void Draw();
	virtual void Debug();
	virtual void resetPosition();
	virtual void MakeGizmo();


	glm::vec2 GetNormal() { return m_normal; }
	float GetDistance() { return m_distance; }
	glm::vec4 GetColor() { return m_color; }

	void SetNormal(glm::vec2 a_normal) { m_normal = a_normal; }
	void SetDistance(float a_distance) { m_distance = a_distance; }

protected:

	glm::vec2	m_normal;
	float	    m_distance;
	glm::vec4	m_color;


};

