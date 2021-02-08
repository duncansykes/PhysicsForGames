#pragma once
#include "Vector2.h"
#include "Vector4.h"
#include "Application.h"
#include "Renderer2D.h"

#include "PhysicsScene.h"

class Physics_ProjectApp : public aie::Application {
public:

	Physics_ProjectApp();
	virtual ~Physics_ProjectApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D* m_2dRenderer;
	float posX;
	float posY;
	
	aie::Font* m_font;
	PhysicsScene* m_physicsScene;
};