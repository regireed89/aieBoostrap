#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Vector2.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	
	Vector2 position;
	Vector2 position2;
	Vector2 projectilePos;


protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Texture*       m_shuriken;
	aie::Font*			m_font;
	aie::Audio*			m_audio;

	float m_cameraX, m_cameraY;
	float m_timer;
};