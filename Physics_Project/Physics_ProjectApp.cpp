#include "Physics_ProjectApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
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

	return true;
}

void Physics_ProjectApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void Physics_ProjectApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	static const glm::vec4 colors[] = {
		glm::vec4(1,0,0,1), glm::vec4(0,1,0,1),
		glm::vec4(0,0,1,1), glm::vec4(0.8f,0, 0.5f, 1),
		glm::vec4(0,1,1,1)
	};

	static const int rows = 5;
	static const int cols = 10;

	static const int hSpace = 1;
	static const int vSapce = 1;


	static const glm::vec2 scrExtents(100, 50);
	static const glm::vec2 boxEx(7, 3);
	static const glm::vec2 StartPos((
		-(cols) >> 1)* (boxEx.x * 2) + vSapce + boxEx.x + (vSapce / 2.f), scrExtents.y -
		((boxEx).y * 2) + hSpace
	);

	glm::vec2 pos;
	for (int y = 0; y < rows; y++)
	{
		pos = glm::vec2(StartPos.x, StartPos.y - 
		(y*((boxEx.x+(vSapce / 2.f),
			)))
		);
	}
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
	static float aspect = 16.f / 9.f;
	aie::Gizmos::draw2D(glm::ortho<float>(-100, 100, -100 / aspect, 100 / aspect, -1.f, 1.f));
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}