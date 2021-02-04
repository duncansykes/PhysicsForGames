#include "Physics_ProjectApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <random>
#include "glm\ext.hpp"
#include <Gizmos.h>

Physics_ProjectApp::Physics_ProjectApp() {

}

Physics_ProjectApp::~Physics_ProjectApp() {

}

bool Physics_ProjectApp::startup() {
	

	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	srand(time(NULL));
	return true;
}

void Physics_ProjectApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void Physics_ProjectApp::update(float deltaTime) {


	
	// input example
	aie::Input* input = aie::Input::getInstance();

	
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Physics_ProjectApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}