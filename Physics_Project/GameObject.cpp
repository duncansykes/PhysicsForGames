#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(glm::vec2 a_pos, std::string a_name) : m_position(a_pos), m_objectName(a_name)
{
	isTrig = false;
	isKinematic = false;
	m_tag = " ";
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
}

void GameObject::Draw()
{
}