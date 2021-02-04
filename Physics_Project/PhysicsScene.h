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



protected:

	glm::vec2 m_gravity;
	float m_timeStep;


};

