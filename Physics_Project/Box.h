#pragma once
#include <Gizmos.h>
#include "Rigidbody.h"
#include "Vector2.h"
#include "Vector4.h"
class Box :
	public Rigidbody
{
public:

	Box(mathfs::Vector2 a_position, mathfs::Vector2 a_velocity,
		float a_rotation, float a_mass, float a_width, float a_height);

	Box(mathfs::Vector2 a_position, mathfs::Vector2 a_velocity,
		float a_rotation, float a_mass, float a_width, float a_height, mathfs::Vector4 a_color);

	~Box();
	
	virtual void FixedUpdate(mathfs::Vector2 a_gravity, float a_timestep);
	virtual void MakeGizmo();

	bool CheckBoxCorners(const Box& a_box, mathfs::Vector2& a_contact,
		int& a_numberContacts, float& pen, mathfs::Vector2 a_edgeNormal);

	float GetWidth() { return m_extents.x * 2; }
	float GetHeight() { return m_extents.y * 2; }
	
	mathfs::Vector2 GetExtents() const { return m_extents; }
	mathfs::Vector4 GetColor() { return m_color; }
	
	mathfs::Vector2 GetLocalX() { return m_localX; }
	mathfs::Vector2 GetLocalY() { return m_localY; }

	
	void SetExtents(mathfs::Vector2 a_extents) { a_extents = m_extents; }
	void SetColor(mathfs::Vector4 a_color) { m_color = a_color; }
	void SetLocals(mathfs::Vector4 a_locals) { m_localX.x = a_locals.x, m_localX.y = a_locals.y, m_localY.x = a_locals.z, m_localY.y = a_locals.w; }



protected:

	mathfs::Vector2 m_extents;
	mathfs::Vector4 m_color;

	mathfs::Vector2 m_localX;
	mathfs::Vector2 m_localY;



};

