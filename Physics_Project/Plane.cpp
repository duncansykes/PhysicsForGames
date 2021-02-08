#include "Plane.h"

#include <Gizmos.h>

Plane::Plane(mathfs::Vector2 a_normal, float a_distance) : PhysicsObject(PLANE)
{
	m_normal = a_normal;
	m_distance = a_distance;
	m_color = mathfs::Vector4(0, 1, 0, 1);
}

Plane::Plane() : PhysicsObject(PLANE)
{
	m_normal = mathfs::Vector2(0, 1);
	m_distance = 0;
	m_color = mathfs::Vector4(1, 1, 1, 1);
}

Plane::~Plane()
{
}

void Plane::FixedUpdate(mathfs::Vector2 a_gravity, float a_timeStep)
{
}

void Plane::Draw()
{
}

void Plane::Debug()
{
}

void Plane::resetPosition()
{
}

void Plane::MakeGizmo()
{
	float lineSegmentLen = 300.f;
	mathfs::Vector2 centrePoint = GetNormal() * m_distance;

	mathfs::Vector2 parallel(GetNormal().y, -GetNormal().x);
	mathfs::Vector4 colorFade = m_color;
	colorFade.w = 0;
	mathfs::Vector2 start = centrePoint + (parallel * lineSegmentLen);
	mathfs::Vector2 end = centrePoint - (parallel * lineSegmentLen);

	glm::vec2 norm(GetNormal().x, GetNormal().y);
	glm::vec2 s(start.x, start.y);
	glm::vec2 e(end.x, end.y);
	glm::vec4 col(m_color.x, m_color.y, m_color.z, m_color.y);
	glm::vec4 colf(colorFade.x, colorFade.y, colorFade.z, colorFade.w);

	aie::Gizmos::add2DTri(s, e, s - norm * 10.f, col, col, colf);
	aie::Gizmos::add2DTri(e, e - norm * 10.f, s - norm * 10.f, col, colf, colf);
}