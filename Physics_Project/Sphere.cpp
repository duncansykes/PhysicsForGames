#include "Sphere.h"
#include <Gizmos.h>

Sphere::Sphere(glm::vec2 a_position, glm::vec2 a_velocity, float a_radius, float a_mass, glm::vec4 a_color)
	: Rigidbody(SPHERE, a_position, a_velocity, 0, a_mass)
{
	m_radius = a_radius;
	m_color = a_color;

}


void Sphere::MakeGizmo()
{
	aie::Gizmos::add2DCircle(m_position, m_radius, 12, m_color);
}

bool Sphere::CheckCollision(PhysicsObject* pOther)
{
	Sphere* pSphere = dynamic_cast<Sphere*>(pOther);

	if (pSphere != nullptr)
	{
		float dist = glm::distance(GetPosition(), pSphere->GetPosition());
		if (GetRadius() + pSphere->GetRadius() > dist)
		{
			return true;
		}
		
	}

	return false;

}
