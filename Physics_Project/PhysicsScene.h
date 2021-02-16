#pragma once
#include <glm/glm.hpp>
#include <vector>

class Rigidbody;

class PhysicsObject;

class PhysicsScene
{
public:
	PhysicsScene();
	~PhysicsScene();

	void addActor(PhysicsObject* a_actor);
	void removeActor(PhysicsObject* a_actor);

	// This will call the update of each PhysicsObject and updates internally.
	// This will handle collision detection and resolution
	void update(float dt);

	// Called once per frame and handles the rendering of PhysicsObject.
	// Will add to a loop of Gizmo objects to render.
	void draw();
	void DebugScene();

	void SetGravity(const glm::vec2 a_gravity) { m_gravity = a_gravity; }
	glm::vec2 GetGravity() const { return m_gravity; }

	void SetTimeStep(const float a_timeStep) { m_timeStep = a_timeStep; }
	float GetTimeStep() const { return m_timeStep; }

	void CheckForCollision();
	static void ApplyContactForces(Rigidbody* a_actor1, Rigidbody* a_actor2, glm::vec2 a_collisionNorm, float a_pen);

	static bool Plane2Plane(PhysicsObject*, PhysicsObject*);
	static bool Plane2Sphere(PhysicsObject*, PhysicsObject*);
	static bool Plane2Box(PhysicsObject*, PhysicsObject*);

	static bool Sphere2Plane(PhysicsObject*, PhysicsObject*);
	static bool Sphere2Sphere(PhysicsObject*, PhysicsObject*);
	static bool Sphere2Box(PhysicsObject*, PhysicsObject*);

	static bool Box2Plane(PhysicsObject*, PhysicsObject*);
	static bool Box2Sphere(PhysicsObject*, PhysicsObject*);
	static bool Box2Box(PhysicsObject*, PhysicsObject*);


	void SetPole(Rigidbody* pole) { m_pole = pole; }
	Rigidbody* GetPole() { return m_pole; }

	void SetBall(Rigidbody* ball) { m_ball = ball; }
	Rigidbody* GetBall() { return m_ball; }

	float ballsSunk;

	std::vector<Rigidbody*> balls;

protected:
	glm::vec2 m_gravity;
	float m_timeStep;

	Rigidbody* m_pole;
	Rigidbody* m_ball;

	std::vector<PhysicsObject*> m_actors;
};
