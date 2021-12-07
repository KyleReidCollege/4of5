#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		//These calls to spawn will be moved to a new loadLevel() function soon
		//Spawn Thomas and Bob
		m_Thomas.spawn(sf::Vector2f(0, 0), GRAVITY);
		m_Bob.spawn(sf::Vector2f(100, 0), GRAVITY);

		m_TimeRemaining = 10;

		m_NewLevelRequired = false;
	}
	if (m_IsPlaying)
	{
		//Update Thomas
		m_Thomas.update(dtAsSeconds);
		//Update Bob
		m_Bob.update(dtAsSeconds);
		//Count down the time the player has left
		m_TimeRemaining -= dtAsSeconds;
		//Have Thomas and Bob run out of time?
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}
	}//End if playing

	//Set the appropriate view around the appropriate character
	if (m_IsSplitScreen)
	{
		m_LeftView.setCenter(m_Thomas.getCentre());
		m_RightView.setCenter(m_Bob.getCentre());
	}
	else
	{
		//Centre full screen around appropriate character
		if (m_IsCharacter1Selected)
		{
			m_MainView.setCenter(m_Thomas.getCentre());
		}
		else
		{
			m_MainView.setCenter(m_Bob.getCentre());
		}
	}
}