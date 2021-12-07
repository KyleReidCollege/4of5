#include "Engine.h"

Engine::Engine()
{
	//Get screen resolution and create an SFML window and view
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;
	m_Window.create(sf::VideoMode(resolution.x, resolution.y), "Thomas Was Late", sf::Style::Fullscreen);
	
	//Initialise the fullscreen view
	m_MainView.setSize(resolution);
	m_HUDView.reset(sf::FloatRect(0, 0, resolution.x, resolution.y));

	//Initialise the split-screen view
	m_LeftView.setViewport(sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_RightView.setViewport(sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	m_BGLeftView.setViewport(sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_BGRightView.setViewport(sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	
	m_BackgroundTexture = TextureHolder::GetTexture("assets/graphics/background.png");

	//Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
	
	//Load the texture for the background vertex
	m_TextureFiles = TextureHolder::GetTexture("assets/graphics/tiles_sheet.png");
}

void Engine::run()
{
	//Timing
	sf::Clock clock;

	while (m_Window.isOpen())
	{
		sf::Time dt = clock.restart();

		//Update the total game time
		m_GameTimeTotal += dt;

		//Make a decimal fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		//Call each part of the game loop in turn
		input();
		update(dtAsSeconds);
		draw();
	}
}