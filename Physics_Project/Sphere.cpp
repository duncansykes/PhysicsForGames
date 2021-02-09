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
	aie::Gizmos::add2DCircle(GetPosition().vectorToglm(), m_radius, 12, GetColor().vectortoglm());
}

bool Sphere::CheckCollision(PhysicsObject* pOther)
{
	Sphere* pSphere = dynamic_cast<Sphere*>(pOther);



	if (pSphere != nullptr)
	{
		float dist = mathfs::extra::distance(GetPosition(), pSphere->GetPosition());
		if (GetRadius() + pSphere->GetRadius() > dist)
		{
			return true;
		}
	}

	return false;
}