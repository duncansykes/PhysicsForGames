#include "Box.h"

Box::Box(mathfs::Vector2 a_position, mathfs::Vector2 a_velocity, float a_rotation, float a_mass, float a_width, float a_height)
	: Rigidbody(BOX, a_position, a_velocity, a_rotation, a_mass), m_extents(a_width, a_height)
{
	
	m_color = mathfs::Vector4(1, 0, 0, 1);
	m_moment = 1.0f / 3.0f * m_mass * a_width * a_height;

}

Box::Box(mathfs::Vector2 a_position, mathfs::Vector2 a_velocity, float a_rotation, float a_mass, float a_width, float a_height, mathfs::Vector4 a_color)
	: Rigidbody(BOX, a_position, a_velocity, a_rotation, a_mass), m_extents(a_width, a_height)

{
	m_moment = 1.0f / 3.0f * m_mass * a_width * a_height;
	m_color = a_color;
}

Box::~Box()
{
}

void Box::FixedUpdate(mathfs::Vector2 a_gravity, float a_timestep)
{
	Rigidbody::FixedUpdate(a_gravity, a_timestep);
	float cs = cosf(m_rotation);
	float sn = sinf(m_rotation);

	m_localX = mathfs::Vector2(cs, sn).Normalize();
	m_localY = mathfs::Vector2(-sn, cs).Normalize();



}

void Box::MakeGizmo()
{

	mathfs::Vector2 p1 = GetPosition() - GetLocalX() * GetExtents().x - GetLocalY() * GetExtents().y;
	mathfs::Vector2 p2 = GetPosition() + GetLocalX() * GetExtents().x - GetLocalY() * GetExtents().y;
	mathfs::Vector2 p3 = GetPosition() - GetLocalX() * GetExtents().x + GetLocalY() * GetExtents().y;
	mathfs::Vector2 p4 = GetPosition() + GetLocalX() * GetExtents().x + GetLocalY() * GetExtents().y;

	aie::Gizmos::add2DTri(p1.vectorToglm(), p2.vectorToglm(), p4.vectorToglm(), m_color.vectortoglm());
	aie::Gizmos::add2DTri(p1.vectorToglm(), p4.vectorToglm(), p3.vectorToglm(), m_color.vectortoglm());

}

bool Box::CheckBoxCorners(const Box& a_box, mathfs::Vector2& a_contact, int& a_numberContacts, float& a_pen, mathfs::Vector2 a_edgeNormal)
{
	float minX, maxX, minY, maxY;
	float boxW = a_box.GetExtents().x * 2;
	float boxH = a_box.GetExtents().y * 2;

	int numLocalC = 0;
	mathfs::Vector2 localContacts(0, 0);
	bool first = true;

	for (float x = -a_box.GetExtents().x; x < boxW; x+= boxW)
	{
		for (float y = -a_box.GetExtents().y; y < boxH; y += boxH)
		{
			mathfs::Vector2 p(a_box.GetPosition() +  (a_box.m_localX.x * x + a_box.m_localX.y * x ) +  (a_box.m_localY.y * y + a_box.m_localY.y * y ));

			mathfs::Vector2 p0(mathfs::extra::dot(p - m_position, m_localX), mathfs::extra::dot(p - m_position, m_localY));

			if (first || p0.x < minX) {
				minX = p0.x;
			}
			if (first || p0.x > maxX) {
				maxX = p0.x;
			}
			if (first || p0.y < minX) {
				minY = p0.y;
			}				
			if (first || p0.y > maxX) {
				maxY = p0.y;
			}

			if (p0.x >= -m_extents.x && p0.x <= m_extents.x &&
				p0.y >= -m_extents.y && p0.y <= m_extents.y) {

				numLocalC++;
				localContacts += p0;

			}
			first = false;
		}
	}

	if (maxX <= -m_extents.x || minX >= m_extents.x ||
		maxY <= -m_extents.y || minX >= m_extents.x) {
		return false;
	}
	if (numLocalC == 0)
		return false;
	
	bool res = false;
	a_contact += m_position + (localContacts.x * m_localX.vectorToglm() + localContacts.y * m_localY.vectorToglm()) / (float)numLocalC;
	a_numberContacts++;

	// Find the minimum penetration vector as a penetration amount and normal
	float pen0 = m_extents.x - minX;

	if (pen0 > 0 && (pen0 < a_pen || a_pen ==0))
	{
		a_edgeNormal = m_localX;
		a_pen = pen0;
		res = true;
	}

	pen0 = maxX + m_extents.x;
	if (pen0 > 0 && (pen0 < a_pen || a_pen == 0))
	{
		a_edgeNormal = mathfs::Vector2(-m_localX.x, -m_localX.y);
		a_pen = pen0;
		res = true;
	}

	pen0 = m_extents.y - minY;
	if (pen0 > 0 && (pen0 < a_pen || a_pen == 0))
	{
		a_edgeNormal = m_localY;
		a_pen = pen0;
		res = true;
	}

	pen0 = maxY + m_extents.y;
	if (pen0 > 0 && (pen0 < a_pen || a_pen == 0))
	{
		a_edgeNormal = mathfs::Vector2(-m_localY.x, -m_localY.y);
		a_pen = pen0;
		res = true;
	}

	return res;
}
