#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Vector2.h"
#include <fstream>

class Bullets
{
public:
	Bullets() {};
	Vector2 position;
	bool isFired = false;

};
class Player
{
public:
	bool m_state;
	Player() {}
	Player(Vector2 pos)
	{
		position = pos;
		m_amao = 99;
		for (int i = 0; i < 100; i++)
		{
			bullets[i] = Bullets();
		}
	}
	int m_amao;
	Vector2 position;
	Bullets bullets[100];
};


class Agent
{
public:
	Agent() {};
	Agent(Vector2 pos, Vector2 velo) 
	{
		position = pos;
		velocity = velo;
	}
	bool AddForce(Vector2 force, float dt);

	Vector2 position;
	Vector2 velocity;
	float mass;

};


class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	
	
	Vector2 playerPos;
	Player Shiruken;
	Agent Regi;
	Agent shur;
	void playerState();
	

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Texture*       m_shuriken;
	aie::Texture*		m_backGround;
	aie::Font*			m_font;
	aie::Audio*			m_audio;

	float m_cameraX, m_cameraY;
	float m_timer;
};

