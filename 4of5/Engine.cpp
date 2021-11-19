#include "Engine.h"

void Engine::input()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			//Handle the player quitting
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				m_Window.close();
			}
			//Handle the player starting the game
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				m_IsPlaying = true;
			}
			//Switch between Thomas and Bob
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				m_IsCharacter1Selected = !m_IsCharacter1Selected;
			}
			//Switch between full and split-screen
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			{
				m_IsSplitScreen = !m_IsSplitScreen;
			}
		}
	}
}

void Engine::update(float dtAsSeconds)
{
}

void Engine::draw()
{
}

Engine::Engine()
{
	//Get screen resolution and create an SGML window and view
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;
	m_Window.create(sf::VideoMode(resolution.x, resolution.y), "Thomsas Was Late", sf::Style::Fullscreen);
	
	//Initialise the fullscreen view
	m_MainView.setSize(resolution);
	m_HUDView.reset(sf::FloatRect(0, 0, resolution.x, resolution.y));

	//Initialise the split-screen view
	m_LeftView.setViewport(sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_RightView.setViewport(sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	m_BGLeftView.setViewport(sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_BGRightView.setViewport(sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	
	m_BackgroundTexture = TextureHolder::GetTexture("graphics/background.png");

	//Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
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
