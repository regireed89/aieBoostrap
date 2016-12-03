#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}
  
bool Application2D::startup() {

	YaBoy = Player(Vector2(600,400));
	
	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/genji.png");
	m_shuriken = new aie::Texture("./textures/ninja.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_audio = new aie::Audio("./audio/powerup.wav");

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
	position = Vector2(600, 400);
	position2 = Vector2(600, 400);
	projectilePos = Vector2(600, 400);
	return true;
}

void Application2D::shutdown() {

	delete m_audio;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// use arrow keys to move camera

	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		YaBoy.position.y += 500.0f*deltaTime;
		projectilePos.y += 500.0f*deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		YaBoy.position.y -= 500.0f * deltaTime;
		projectilePos.y -= 500.0f*deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		YaBoy.position.x -= 500.0f * deltaTime;
		projectilePos.x -= 500.0f*deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		YaBoy.position.x += 500.0f * deltaTime;
		projectilePos.x += 500.0f*deltaTime;
	}



	// example of audio
	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		YaBoy.bullets[YaBoy.m_amao].position = YaBoy.position;
		YaBoy.m_amao--;
		YaBoy.bullets[YaBoy.m_amao].isFired = true;
		YaBoy.position.x += 10.0f;
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

}

void Application2D::draw() {
	;
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	// demonstrate animation
	m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
	m_2dRenderer->drawSprite(m_texture, 200, 200, 50, 50);

	// demonstrate spinning sprite
	m_2dRenderer->setUVRect(0, 0, 1, 1);
	m_2dRenderer->drawSprite(m_shipTexture, projectilePos.x, projectilePos.y, 0, 0, 0, 1);

	//draw shuriken
	for (int i = 0; i < 100; i++)
	{
		if (YaBoy.bullets[i].isFired)
		{
			m_2dRenderer->setUVRect(0, 0, 1, 1);
			m_2dRenderer->drawSprite(m_shuriken, YaBoy.bullets[i].position.x, YaBoy.bullets[i].position.y, 100, 100, 0);
		}
	}
	

	// draw a thin line
	//m_2dRenderer->drawLine(600, 400, position2.x, position2.y, 2, 1);

	// draw a moving purple circle
	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	// draw a rotating red box
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	// draw a slightly rotated sprite with no texture, coloured yellow
	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press Space to WHOOP SOME ASS!!!!!", 0, 720 - 64);
	
	// done drawing sprites
	m_2dRenderer->end();
}


