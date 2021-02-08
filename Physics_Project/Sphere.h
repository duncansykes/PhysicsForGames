#pragma once
#include "Rigidbody.h"

class Sphere : public Rigidbody
{
public:

	Sphere(mathfs::Vector2 a_position, mathfs::Vector2 a_velocity,
		float a_radius, float a_mass, mathfs::Vector4 a_color);
	~Sphere() {};

	virtual void MakeGizmo();
	bool CheckCollision(PhysicsObject* pOther);

	float GetRadius() { return m_radius; }
	mathfs::Vector4 GetColor() { return m_color; }

protected:

	float m_radius;
	mathfs::Vector4 m_color;
};
