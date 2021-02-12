#pragma once

#include "Sphere.h"
#include "Plane.h"
#include "Box.h"
#include "Spring.h"
#include "glm\ext.hpp"
#include <string>

class GameObject
{
public:

	GameObject();
	GameObject(glm::vec2 a_pos, std::string a_name);
	virtual ~GameObject();

	virtual void Update();
	virtual void Draw();

	glm::vec2 SetPosition(glm::vec2 a_pos) { return m_position = a_pos; }
	bool Trigger(bool state) { return isTrig = state; }
	bool Kinematic(bool state) { return isKinematic = state; }

	std::string name(std::string name) { return m_objectName = name; }
	std::string tag(std::string tag) { return m_tag = tag; }

	std::vector<GameObject*> AllObjects;

protected:

	glm::vec2 m_position;

	bool isTrig;
	bool isKinematic;
	std::string m_objectName;
	std::string m_tag;
};
