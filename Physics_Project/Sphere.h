#pragma once
#include "Rigidbody.h"

class Sphere : public Rigidbody
{
public:
	Sphere(glm::vec2 a_position, glm::vec2 a_velocity, float a_mass, float a_radius, glm::vec4 a_colour);
	~Sphere();

	virtual void MakeGizmo();
	virtual bool IsInside(glm::vec2 a_point);

	float GetRadius() { return m_radius; }
	glm::vec4 GetColour() { return m_color; }

protected:
	float m_radius;
	glm::vec4 m_color;
};
