#pragma once
#include "PhysicsObject.h"


// This is a one sided object that extends infinitely along both its edge
// and backwards from its normal direction.

class Plane : public PhysicsObject
{
public:
	Plane(mathfs::Vector2 a_normal, float a_distance);
	Plane();
	~Plane();

	virtual void FixedUpdate(mathfs::Vector2 a_gravity, float a_timeStep);
	virtual void Draw();
	virtual void Debug();
	virtual void resetPosition();
	virtual void MakeGizmo();

	mathfs::Vector2 GetNormal() { return m_normal; }
	float GetDistance() { return m_distance; }
	mathfs::Vector4 GetColor() { return m_color; }

	void SetNormal(mathfs::Vector2 a_normal) { m_normal = a_normal; }
	void SetDistance(float a_distance) { m_distance = a_distance; }

protected:

	mathfs::Vector2	m_normal;
	float	    m_distance;
	mathfs::Vector4	m_color;
};
