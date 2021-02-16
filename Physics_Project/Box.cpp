#include <Gizmos.h>
#include "Box.h"

Box::Box(glm::vec2 a_position, glm::vec2 a_velocity, float a_rotation, float a_mass, float a_width, float a_height)
	: Rigidbody(BOX, a_position, a_velocity, a_rotation, a_mass)
{
	m_extents = glm::vec2(a_width, a_height);
	m_color = glm::vec4(1, 0, 0, 1);
	/*m_moment = 1.0f / 3.0f * m_mass * a_width * a_height;
	
	m_rotation = a_rotation;*/

	
}

Box::Box(glm::vec2 a_position, glm::vec2 a_velocity, float a_rotation, float a_mass, float a_width, float a_height, glm::vec4 a_color)
	: Rigidbody(BOX, a_position, a_velocity, a_rotation, a_mass)
{
	m_extents = glm::vec2(a_width, a_height);
	m_color = a_color;
	/*m_moment = 1.0f / 3.0f * m_mass * a_width * a_height;
	m_rotation = a_rotation;*/
}

Box::~Box()
{
}

void Box::FixedUpdate(glm::vec2 a_gravity, float a_timeStep)
{
	Rigidbody::FixedUpdate(a_gravity, a_timeStep);

	float cs = cosf(m_rotation);
	float sn = sinf(m_rotation);

	m_localX = glm::normalize(glm::vec2(cs, sn));
	m_localY = glm::normalize(glm::vec2(-sn, cs));
}

void Box::MakeGizmo()
{
	glm::vec2 p1 = m_position - m_localX * m_extents.x - m_localY * m_extents.y;
	glm::vec2 p2 = m_position + m_localX * m_extents.x - m_localY * m_extents.y;
	glm::vec2 p3 = m_position - m_localX * m_extents.x + m_localY * m_extents.y;
	glm::vec2 p4 = m_position + m_localX * m_extents.x + m_localY * m_extents.y;

	aie::Gizmos::add2DTri(p1, p2, p4, m_color);
	aie::Gizmos::add2DTri(p1, p4, p3, m_color);

	
}

bool Box::CheckBoxCorners(const Box& a_box, glm::vec2& a_contact, int& a_numContacts, float& a_pen, glm::vec2& a_edgeNormal)
{
	float minX, maxX, minY, maxY;
	float boxW = a_box.GetExtents().x * 2;
	float boxH = a_box.GetExtents().y * 2;
	int numLocalContacts = 0;
	glm::vec2 localContact(0, 0);
	bool first = true;

	// Loop over all the corners of the other box
	for (float x = -a_box.GetExtents().x; x < boxW; x += boxW)
	{
		for (float y = -a_box.GetExtents().y; y < boxH; y += boxH)
		{
			// Get the position in world space
			glm::vec2 pos = a_box.GetPosition() + x * a_box.m_localX + y * a_box.m_localY;

			// Get the position in our box's space
			glm::vec2 boxPos(glm::dot(pos - m_position, m_localX), glm::dot(pos - m_position, m_localY));

			// Update the extents in each cardinal direction of our box's space
			// Extents along the separating axes
			if (first || boxPos.x < minX)
			{
				minX = boxPos.x;
			}

			if (first || boxPos.x > maxX)
			{
				maxX = boxPos.x;
			}

			if (first || boxPos.y < minY)
			{
				minY = boxPos.y;
			}

			if (first || boxPos.y > maxY)
			{
				maxY = boxPos.y;
			}

			if (boxPos.x >= -m_extents.x && boxPos.x <= m_extents.x &&
				boxPos.y >= -m_extents.y && boxPos.y <= m_extents.y)
			{
				numLocalContacts++;
				localContact += boxPos;
			}

			first = false;
		}
	}

	// If we lie entirely to one side of the box along one axis, we've found a separatin axis, and we can exit

	if (maxX <= -m_extents.x || minX >= m_extents.x ||
		maxY <= -m_extents.y || minY >= m_extents.y)
	{
		return false;
	}

	if (numLocalContacts == 0)
	{
		return false;
	}

	bool res = false;
	a_contact += m_position + (localContact.x * m_localX + localContact.y * m_localY) / (float)numLocalContacts;
	a_numContacts++;

	// Find the minimum penetration vector as a penetration amount and normal
	float pen0 = m_extents.x - minX;
	if (pen0 > 0 && (pen0 < a_pen || a_pen == 0))
	{
		a_edgeNormal = m_localX;
		a_pen = pen0;
		res = true;
	}

	pen0 = maxX + m_extents.x;
	if (pen0 > 0 && (pen0 < a_pen || a_pen == 0))
	{
		a_edgeNormal = -m_localX;
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
		a_edgeNormal = -m_localY;
		a_pen = pen0;
		res = true;
	}

	return res;
}