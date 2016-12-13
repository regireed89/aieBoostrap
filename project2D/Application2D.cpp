#include "Application2D.h" 
#include "Vector2.h"
#include "Texture.h" 
#include "Font.h" 
#include "Input.h" 
using namespace std;



Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {

	Shiruken = Player(Vector2(600, 400));
	Regi = Agent(Vector2(600, 400), Vector2(1, 0));

	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/genji.png");
	m_shuriken = new aie::Texture("./textures/ninja.png");
	m_backGround = new aie::Texture("./textures/original.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);
	   
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
	
	playerPos = Vector2(600, 400);
	
	return true;
}

void Application2D::shutdown() {

	
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
	delete m_backGround;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;
	
	

	// input example 
	aie::Input* input = aie::Input::getInstance();

	// use arrow keys to move player

	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		Shiruken.position.y += 500.0f*deltaTime;
		Regi.position.y += 500.0f*deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		Shiruken.position.y -= 500.0f * deltaTime;
		Regi.position.y -= 500.0f*deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		Shiruken.position.x -= 500.0f * deltaTime;
		Regi.position.x -= 500.0f*deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		Shiruken.position.x += 500.0f * deltaTime;
		Regi.position.x += 500.0f*deltaTime;
	}

	// example of audio 
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		Shiruken.bullets[Shiruken.m_amao].position = Shiruken.position;
		Shiruken.m_amao--;
		Shiruken.bullets[Shiruken.m_amao].isFired = true;
		Shiruken.position.x;
	}

	// exit the application 
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

}

void Application2D::draw() {
	;
	// wipe the screen to the background colour 
	clearScreen();

	m_2dRenderer->setUVRect(0, 0, 1, 1);
	m_2dRenderer->drawSprite(m_backGround, 630, 300, 0, 0, 0, 1);

	// set the camera position before we begin rendering 
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites  
	m_2dRenderer->begin();

	// demonstrate animation 
	m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
	m_2dRenderer->drawSprite(m_texture, 200, 200, 50, 50);

	//draw shuriken  
	for (int i = 0; i < 100; i++)
	{

		if (Shiruken.bullets[i].isFired)
		{
			m_2dRenderer->setUVRect(0, 0, 1, 1);
			m_2dRenderer->drawSprite(m_shuriken, Shiruken.bullets[i].position.x, Shiruken.bullets[i].position.y, 100, 100, 0);
		}
	}

	// demonstrate spinning sprite 
	m_2dRenderer->setUVRect(0, 0, 1, 1);
	m_2dRenderer->drawSprite(m_shipTexture,Regi.position.x, Regi.position.y, 0, 0, 0, 1);
	Regi.AddForce(Vector2(.001, 0), 1);



	// draw a thin line
	//m_2dRenderer->drawLine(600, 400, position2.x, position2.y, 2, 1);

	// draw a moving purple circle
	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	//m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	// draw a rotating red box
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	//m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	// draw a slightly rotated sprite with no texture, coloured yellow
	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	//m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press Space to WHOOP SOME ASS!!!!!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}

#include <fstream>


void Application2D::playerState()
{

	fstream *file = new fstream();
	file->open("GameState.yaboy", ios_base::out);
	if (file->is_open())
	{
		*file << "its yaboy" << endl;
	}
	file->close();

}

//void Application2D::getPlayer()
//{
//	char data2;
//	string data;
//	fstream*file = new fstream("GameState.yaboy");
//	file->close();
//	if (file->is_open())
//	{
//		file >> data;
//		file->get(data);
//	}
//	while (getline(file, data))
//	{
//		cout << data << endl;
//	}
//	file->close();
//}

bool Agent::AddForce(Vector2 force, float dt)
{

	position = (position + velocity)*dt;
	velocity = (velocity + force)*dt;

	return false;
}
