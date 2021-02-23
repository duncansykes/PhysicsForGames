#include "Physics_ProjectApp.h"
#include "GameObject.h"
#include "Sphere.h"
#include "Plane.h"
#include "Box.h"
#include "Spring.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "glm\ext.hpp"
#include <Gizmos.h>
#include <random>
#include <iostream>

Physics_ProjectApp::Physics_ProjectApp()
{
	RED = glm::vec4(1, 0, 0, 1);
	GREEN = glm::vec4(0, 1, 0, 1);
	REDLINES = glm::vec4(1, 0, 0, 0);
	BLUE = glm::vec4(0, 0, 1, 1);
	WHITELINES = glm::vec4(1, 1, 1, 0);
	GREENLINES = glm::vec4(0, 1, 0, 0);
}

Physics_ProjectApp::~Physics_ProjectApp()
{
}

bool Physics_ProjectApp::startup()
{
	// Increases 2D line coun to maximise the number of objects we can draw.
	aie::Gizmos::create(10000U, 10000U, 65535U, 65535U);

	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_physicsScene = new PhysicsScene();

	m_physicsScene->SetGravity(glm::vec2(0, -0));

	// Lower the valu, the more accurate the simulation will be;
	// but it will increase the processing time required.
	// If it is too high it causes the sim to stutter and reduce stability.
	m_physicsScene->SetTimeStep(0.01f);
	sphereNumber = 1;
	
	GameScene(10);
	return true;
}

void Physics_ProjectApp::shutdown()
{
	delete m_font;
	delete m_2dRenderer;
}

void Physics_ProjectApp::update(float deltaTime)
{
	// input example
	aie::Input* input = aie::Input::getInstance();
	aie::Gizmos::clear();

	// Update physics scene
	m_physicsScene->update(deltaTime);


	float maxDist = 30.f;

	for (auto ball : m_physicsScene->balls)
	{
		if (ball->InHole == true)
		{
			m_physicsScene->removeActor(ball);
			auto it = std::find(m_physicsScene->balls.begin(), m_physicsScene->balls.end(), ball);

			if (it != m_physicsScene->balls.end())
			{
				m_physicsScene->balls.erase(it);
			}
		}
	}

	// Get mouse position on screen
	int xScreen, yScreen;
	input->getMouseXY(&xScreen, &yScreen);
	glm::vec2 worldPos = ScreenToWorld(glm::vec2(xScreen, yScreen));

	// Set mouse velocity
	m_mouseVelocity = (-worldPos - -m_prevPos) / deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		aie::Gizmos::add2DLine(whiteBall->GetPosition(), m_physicsScene->balls[iteratorDebug]->GetPosition(), glm::vec4(1, 1, 1, 1));

	}
	if (input->wasKeyReleased(aie::INPUT_KEY_D))
	{
		iteratorDebug = iteratorDebug + 1;


	}
	if (iteratorDebug >= m_physicsScene->balls.size())
	{
		iteratorDebug = 0;
	}
	if (m_physicsScene->balls.size() == 0)
	{
		aie::Application::destroyWindow();
	}
	// Check state of mouse button
	if (input->isMouseButtonDown(0))
	{
		// add iterator keybind


		lineLength = glm::distance(worldPos, whiteBall->GetPosition());

		std::cout << lineLength << std::endl;

		if (lineLength <= maxDist)
		{
			aie::Gizmos::add2DLine(whiteBall->GetPosition(), worldPos, glm::vec4(1, 1, 1, 1));
			velo = (worldPos - whiteBall->GetPosition()) / deltaTime;


		}
		else
		{

		}

		m_physicsScene->GetPole()->SetPosition(worldPos);

		pole->SetColor(glm::vec4(1, 0, 1, 0));
	}
	if (input->wasMouseButtonReleased(0))
	{
		if (lineLength <= maxDist)
		{
			whiteBall->SetVelocity(-velo / 10.f);
		}
		pole->SetTrigger(true);
		pole->SetColor(glm::vec4(0, 0, 0, 0));
		velo = glm::vec2(0);
	}


	if (m_physicsScene->ballsSunk >= 1)
	{
		//std::cout << " 1 sunk" << std::endl;
	}

	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		whiteBall->SetVelocity(glm::vec2(0));
		whiteBall->SetPosition(glm::vec2(-30, 0));
	}

	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		m_physicsScene->GetPole()->SetRotation(m_physicsScene->GetPole()->GetRotation() + 0.1f);
	}
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		m_physicsScene->GetPole()->SetRotation(m_physicsScene->GetPole()->GetRotation() + -0.1f);
	}

	m_prevPos = worldPos;

	m_physicsScene->draw();
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Physics_ProjectApp::draw()
{
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// If X-axis = -100 to 100, Y-axis = -56.25 to 56.25
	aie::Gizmos::draw2D(glm::ortho<float>(-m_extents, m_extents, -m_extents / m_aspectRatio, m_extents / m_aspectRatio, -1.0f, 1.0f));

	char fps[32];
	sprintf_s(fps, 32, "Sunk: %i", (int)m_physicsScene->ballsSunk);
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}

glm::vec2 Physics_ProjectApp::ScreenToWorld(glm::vec2 a_screenPos)
{
	glm::vec2 worldPos = a_screenPos;

	// We will move the center of the screen to (0, 0)
	worldPos.x -= getWindowWidth() / 2;
	worldPos.y -= getWindowHeight() / 2;

	// Scale this according to the extents
	worldPos.x *= 2.0f * m_extents / getWindowWidth();
	worldPos.y *= 2.0f * m_extents / (m_aspectRatio * getWindowHeight());

	return worldPos;
}

void Physics_ProjectApp::TriggerTest()
{
	Sphere* ball = new Sphere(glm::vec2(-30, 0), glm::vec2(13, 0), 4, 4, glm::vec4(1, 0, 0, 1));

	Sphere* ball2 = new Sphere(glm::vec2(0, -20), glm::vec2(0), 4, 4, glm::vec4(0, 0.5, 0.5, 1));

	ball2->SetKinematic(true);
	ball2->SetTrigger(true);

	m_physicsScene->addActor(ball);
	m_physicsScene->addActor(ball2);
	m_physicsScene->addActor(new Plane(glm::vec2(0, 1), -30));
	m_physicsScene->addActor(new Plane(glm::vec2(1, 0), -50));
	m_physicsScene->addActor(new Plane(glm::vec2(-1, 0), -50));
	m_physicsScene->addActor(new Box(glm::vec2(20, 10), glm::vec2(3, 0), 0.5f, 4, 8, 4));
	m_physicsScene->addActor(new Box(glm::vec2(-45, 10), glm::vec2(3, 0), 0.5f, 4, 8, 4));

	ball2->triggerEnter = [=](PhysicsObject* other) { std::cout << "Entered: " << other << std::endl; };

	ball2->triggerExit = [=](PhysicsObject* other) { std::cout << "Exited : " << other << std::endl; };
}

void Physics_ProjectApp::DrawRect()
{
	m_physicsScene->addActor(new Sphere(glm::vec2(20, 10), glm::vec2(-10, -17), 1, 3, glm::vec4(1, 0, 0, 1)));
	m_physicsScene->addActor(new Plane(glm::vec2(-0.65, 0.75), -25));

	Box* box1 = new Box(glm::vec2(-20, 0), glm::vec2(16, -4), 1, 4, 8, 4, glm::vec4(1, 0, 0, 1));
	box1->SetRotation(0.5f);

	Box* box2 = new Box(glm::vec2(10, 0), glm::vec2(-4, 0), 1, 4, 8, 4, glm::vec4(0, 1, 0, 1));

	m_physicsScene->addActor(box1);
	m_physicsScene->addActor(box2);

	box1->ApplyForce(glm::vec2(30, 0), glm::vec2(0));
	box2->ApplyForce(glm::vec2(-15, 0), glm::vec2(0));

	Sphere* ball = new Sphere(glm::vec2(5, 10), glm::vec2(0), 1, 3, glm::vec4(0, 0, 1, 1));
	ball->SetRotation(0.5);
	m_physicsScene->addActor(ball);
	ball->SetKinematic(true);
}

void Physics_ProjectApp::SphereAndPlane()
{
	Sphere* ball1;
	ball1 = new Sphere(glm::vec2(-40, 40), glm::vec2(0), 3.0f, 1, glm::vec4(1, 0, 0, 1));
	m_physicsScene->addActor(ball1);
	ball1->ApplyForce(glm::vec2(50, 30), glm::vec2(0));

	Sphere* ball2;
	ball2 = new Sphere(glm::vec2(40, 40), glm::vec2(0), 3.0f, 1, glm::vec4(0, 1, 0, 1));
	m_physicsScene->addActor(ball2);
	ball2->ApplyForce(glm::vec2(-50, 30), glm::vec2(0));

	Plane* plane = new Plane();
	m_physicsScene->addActor(plane);
}

void Physics_ProjectApp::SpringTest(int a_amount)
{
	Sphere* prev = nullptr;
	for (int i = 0; i < a_amount; i++)
	{
		// This will need to spawn the sphere at the bottom of the previous one,
		// to make a pendulum that is effected by gravity
		Sphere* sphere = new Sphere(glm::vec2(i * 3, 30 - i * 5), glm::vec2(0), 10, 2, glm::vec4(0, 0, 1, 1));

		if (i == 0)
		{
			sphere->SetKinematic(true);
		}

		m_physicsScene->addActor(sphere);

		if (prev)
		{
			m_physicsScene->addActor(new Spring(sphere, prev, 10, 500));
		}

		prev = sphere;
	}

	Box* box = new Box(glm::vec2(0, -20), glm::vec2(0), 0.3f, 20, 8, 2);
	Box* box2 = new Box(glm::vec2(-5, 15), glm::vec2(50, 0), 0.3f, 20, 8, 2);
	m_physicsScene->addActor(box2);
	box->SetKinematic(true);
	m_physicsScene->addActor(box);
}

void Physics_ProjectApp::GameScene(int a_amount)
{
	int fr = 3;
	float spacing_X = 90;
	float spacing_Y = 50;
	float sizeOfHole = 5;

	pole = new Sphere(glm::vec2(0, 0), glm::vec2(0), 1, 0.5,glm::vec4(0, 0, 0, 0));
	pole->SetElasticity(2);
	pole->ShowLine = false;
	m_physicsScene->SetPole(pole);
	m_physicsScene->addActor(pole);


	m_physicsScene->GetPole()->SetRotation(0);
	m_physicsScene->ballsSunk = 0;

	GenerateStart();

	for (int i = 0; i < fr; i++)
	{
		glm::vec2 posFinal(0, 0);

		hole = new Sphere(glm::vec2(-spacing_X + (i * spacing_X) + 0, -spacing_Y), glm::vec2(0), 10, sizeOfHole, GREENLINES);
		hole->ShowLine = false;
		posFinal = glm::vec2(-50 + (i * 30), -20);
		hole->SetKinematic(true); hole->SetTrigger(true);

		hole->triggerEnter = [=](PhysicsObject* other)
		{
		

			std::cout << "Entered: " << other << std::endl;
			for (auto ball : m_physicsScene->balls)
			{
				if (other == ball)
				{		
					ball->InHole = true;	
					/*if (glm::distance(hole->GetPosition(), ball->GetPosition()) < 2.f);
					{
						std::cout << "Ball sunk" << "\n";
						m_physicsScene->ballsSunk = m_physicsScene->ballsSunk + 1;

						auto it = std::find(m_physicsScene->balls.begin(), m_physicsScene->balls.end(),ball);

						if (it != m_physicsScene->balls.end())
						{
							m_physicsScene->balls.erase(it);
						}
						

					}*/		
				}
			}
		};

		m_physicsScene->addActor(hole);
	}
	for (int i = 0; i < fr; i++)
	{
		glm::vec2 posFinal(0, 0);
		hole = new Sphere(glm::vec2(-spacing_X + (i * spacing_X) + 0, spacing_Y), glm::vec2(0), 10, sizeOfHole, GREENLINES);
		hole->ShowLine = false;

		posFinal = glm::vec2(-50 + (i * 30), -20);
		hole->SetKinematic(true); hole->SetTrigger(true);
		hole->triggerEnter = [=](PhysicsObject* other)
		{

			/*if (other == whiteBall)
			{			
				whiteBall->SetPosition(glm::vec2(-5, 5));
				whiteBall->SetVelocity(glm::vec2(0));		
			}*/

			std::cout << "Entered: " << other << std::endl;
			for (auto ball : m_physicsScene->balls)
			{
				if (other == ball)
				{
					ball->InHole = true;
				}
			}
		};
		m_physicsScene->addActor(hole);
	}
	m_physicsScene->addActor(new Plane(glm::vec2(0, 1), -60));
	m_physicsScene->addActor(new Plane(glm::vec2(1, 0), -100));
	m_physicsScene->addActor(new Plane(glm::vec2(0, -1), -60));
	m_physicsScene->addActor(new Plane(glm::vec2(-1, 0), -100));
}

void Physics_ProjectApp::GenerateStart()
{
	float yAnchor = 20.f;
	float xAnchor = 40.f;
	float spacing = 10.f;

	int yPos = 0;

	for (int a = 0; a <= 10; a++)
	{
		// Backrow = 4 total balls
		if (a <= 4)
		{
			billardBalll = new Sphere(glm::vec2(xAnchor, (yAnchor + -yPos * spacing)), glm::vec2(0), 20, 2, REDLINES);
			billardBalll->SetID(a);
			m_physicsScene->addActor(billardBalll);
			m_physicsScene->balls.push_back(billardBalll);
			if (yPos >= 4)
			{
				yPos = 0;
			}
		}
		// 2nd back row = 3 total balls
		if (a < 7 && a >= 4)
		{
			billardBalll = new Sphere(glm::vec2(xAnchor - 10, 5 + (yAnchor + (-yPos) * spacing)), glm::vec2(0), 20, 2, glm::vec4(0,0,1,0));
			billardBalll->SetID(a);
			m_physicsScene->addActor(billardBalll);
			m_physicsScene->balls.push_back(billardBalll);
		}

		// 2nd FRONT row = 2 total balls
		if (a < 9 && a >= 7)
		{
			if (a == 8)
			{
				billardBalll = new Sphere(glm::vec2(xAnchor - 20, (yAnchor + (-yPos) * spacing)), glm::vec2(0), 20, 2, REDLINES);
			}
			else
			{
				billardBalll = new Sphere(glm::vec2(xAnchor - 20, (yAnchor + (-yPos) * spacing)), glm::vec2(0), 20, 2, glm::vec4(0, 0, 1, 0));
			}
			billardBalll->SetID(a);
			m_physicsScene->addActor(billardBalll);
			m_physicsScene->balls.push_back(billardBalll);

			std::cout << yAnchor + (-yPos) * spacing << std::endl;
			if (yPos >= 2)
			{
				yPos = 0;
			}
		}

		if (yPos >= 3)
		{
			yPos = 0;
		}
		yPos++;
	}

	billardBalll = new Sphere(glm::vec2(xAnchor - 30, (5)), glm::vec2(0), 20, 2, glm::vec4(0, 1, 1, 0)); billardBalll->SetID(10); m_physicsScene->addActor(billardBalll);
	m_physicsScene->balls.push_back(billardBalll);
	whiteBall = new Sphere(glm::vec2(-5, 5), glm::vec2(0), 15, 2, WHITELINES); whiteBall->ObjectName = "WhiteBall"; m_physicsScene->addActor(whiteBall); 
}