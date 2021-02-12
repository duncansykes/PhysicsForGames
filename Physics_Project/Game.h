#pragma once
#include "PhysicsScene.h"
#include "Box.h"
#include "Sphere.h"
#include "Rigidbody.h"

#include <list>

class Game : public PhysicsScene
{
public:

	Game() {};
	~Game() {};

	void StartUp();
	void Draw();
	void Update();

protected:

	float m_radius = 2.f;

	Box* m_playArea;
	Sphere* m_playerBall;

	Sphere* m_balls;
};


