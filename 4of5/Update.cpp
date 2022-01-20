#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		loadLevel();
	}
	if (m_IsPlaying)
	{
		//Update Thomas
		m_Thomas.update(dtAsSeconds);
		//Update Bob
		m_Bob.update(dtAsSeconds);

		//Detect collisions
		if (detectCollisions(m_Thomas) && detectCollisions(m_Bob))
		{
			//New level required
			m_NewLevelRequired = true;

			//Play a victory sound
			m_SM.PlayReachGoal();
		}
		else
		{
			detectCollisions(m_Bob);
		}

		//Let Thomas and Bob jump on each other's heads
		if (m_Bob.getFeet().intersects(m_Thomas.getHead()))
		{
			m_Bob.stopFalling(m_Thomas.getHead().top);
		}
		else if (m_Thomas.getFeet().intersects(m_Bob.getHead()))
		{
			m_Thomas.stopFalling(m_Bob.getHead().top);
		}

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

	m_FramesSinceLastHudUpdate++;
	if (m_FramesSinceLastHudUpdate > m_TargetFramesPerHudUpdate)
	{
		stringstream ssTime;
		stringstream ssLevel;

		ssTime << (int)m_TimeRemaining;
		m_Hud.setTime(ssTime.str());

		ssLevel << "Level: " << m_LM.getCurrentLevel();
		m_Hud.setLevel(ssLevel.str());

		m_FramesSinceLastHudUpdate = 0;
	}

	vector<Vector2f>::iterator it;

	for (it = m_FireEmitters.begin(); it != m_FireEmitters.end(); it++)
	{
		float posX = (*it).x;
		float posY = (*it).y;

		FloatRect localRect(posX - 250, posY - 250, 500, 500);

		if (m_Thomas.getPosition().intersects(localRect))
		{
			m_SM.PlayFire(Vector2f(posX, posY), m_Thomas.getCentre());
		}
	}
}