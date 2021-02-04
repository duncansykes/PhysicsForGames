#include "Physics_ProjectApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <random>
#include "glm\ext.hpp"
#include <Gizmos.h>

Physics_ProjectApp::Physics_ProjectApp()
{

}

Physics_ProjectApp::~Physics_ProjectApp() 
{

}

bool Physics_ProjectApp::startup()
{
	

	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/ComicSansMS3.ttf", 100);


	m_physicsScene = new PhysicsScene();
	
	// Lower the value, the more accurate the simulation
	// but it will increase the processing time required. If it 
	// is too high it will cause the sim to stutter and reduce stability.

	m_physicsScene->setTimeStep(0.01f);



	srand(time(NULL));
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
	m_physicsScene->update(deltaTime);
	m_physicsScene->draw();

	
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Physics_ProjectApp::draw()
{

	// wipe the screen to the background color
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	static float aspectRatio = 16 / 9.f;
	aie::Gizmos::draw(glm::ortho<float>(-100, 100,
		-100 / aspectRatio, 100 / aspectRatio, -1.f, 1.f));
	// draw your stuff here!


	// output some text, uses the last used color
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 10);

	// done drawing sprites
	m_2dRenderer->end();
}