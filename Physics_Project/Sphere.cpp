#include "Sphere.h"
#include <Gizmos.h>

Sphere::Sphere(mathfs::Vector2 a_position, mathfs::Vector2 a_velocity, float a_radius, float a_mass, mathfs::Vector4 a_color)
	: Rigidbody(SPHERE, a_position, a_velocity, 0, a_mass)
{
	m_radius = a_radius;
	m_color = a_color;
}

void Sphere::MakeGizmo()
{

	glm::vec2 pos(m_position.x, m_position.y);
	glm::vec4 col(m_color.x, m_color.y, m_color.z, m_color.w);

	aie::Gizmos::add2DCircle(pos, m_radius, 12, col);
}

bool Sphere::CheckCollision(PhysicsObject* pOther)
{
	Sphere* pSphere = dynamic_cast<Sphere*>(pOther);



	if (pSphere != nullptr)
	{
		float dist = mathfs::extra::dist(GetPosition(), pSphere->GetPosition());
		if (GetRadius() + pSphere->GetRadius() > dist)
		{
			return true;
		}
	}

	return false;
}