#pragma once
#include <glm/glm.hpp>
#include <vector>

class PhysicsObject;

class PhysicsScene
{
public:

	PhysicsScene();
	~PhysicsScene();


	void addActor(PhysicsObject* a_actor);
	void removeActor(PhysicsObject* a_actor);

	void update(float deltaTime);
	void draw();

	void setGravity(const glm::vec2 a_gravity) { m_gravity = a_gravity; }
	glm::vec2 GetGravity() { return m_gravity; }

	void setTimeStep(const float a_timeStep) { m_timeStep = a_timeStep; }
	float getTimeStep() { return m_timeStep; }

protected:

	glm::vec2 m_gravity;
	float m_timeStep;

	std::vector<PhysicsObject*> m_actors;
};

