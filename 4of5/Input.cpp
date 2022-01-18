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
	//Handle input specific to Thomas
	if (m_Thomas.handleInput())
	{
		//Play a jump sound
		m_SM.PlayJump();
	}

	//Handle input specific to Bob
	if (m_Bob.handleInput())
	{
		//Play a jump sound
		m_SM.PlayJump();
	}
}