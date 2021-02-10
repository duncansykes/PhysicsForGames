#pragma once
#include <glm/glm.hpp>
#include "Vector2.h"
#include "Vector4.h"
// This is a pure abstract class. It will be used as a
// base for the derived classes that will use FixedUpdate.

enum ShapeType
{
	PLANE = 0,
	SPHERE,
	BOX,
	SHAPE_COUNT
};

class PhysicsObject
{
public:

	virtual void FixedUpdate(mathfs::Vector2 a_gravity, float a_timeStep) = 0;
	virtual void MakeGizmo() = 0;
	virtual void resetPosition() {}

	virtual void Debug() = 0;

	ShapeType getShapeID() { return m_shapeID; }

	void SetKinematicState(bool a_state) { m_isKinematic = a_state; }

	// Keep to a max of 1 for realism

	float SetElastic(float a_amount) { return m_elasticicty = a_amount; }
	bool isKinematic() { return m_isKinematic; }
	float getElasicity() { return m_elasticicty; }



protected:

	ShapeType m_shapeID;
	bool m_isKinematic;
	float m_elasticicty;

	PhysicsObject(ShapeType a_shapeID) :m_shapeID(a_shapeID) {}
};
