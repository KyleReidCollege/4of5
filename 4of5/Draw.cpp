#include "Engine.h"

void Engine::draw()
{
	//Rub out the last frame
	m_Window.clear(sf::Color::White);
	if (!m_IsSplitScreen)
	{
		//Switch to background view
		m_Window.setView(m_BGMainView);
		//Draw the background
		m_Window.draw(m_BackgroundSprite);
		//Switch to main view
		m_Window.setView(m_MainView);
		//Draw Thomas
		m_Window.draw(m_Thomas.getSprite());
		//Draw Bob
		m_Window.draw(m_Bob.getSprite());
	}
	else
	{
		//Split-screen view is active
		//First draw Thomas' side of the screen
		//Switch to background view
		m_Window.setView(m_BGLeftView);
		//Draw the background
		m_Window.draw(m_BackgroundSprite);
		//Switch to left view
		m_Window.setView(m_LeftView);

		//Draw Bob
		m_Window.draw(m_Bob.getSprite());
		//Draw Thomas
		m_Window.draw(m_Thomas.getSprite());

		//Now draw Bob's side of the screen
		//Switch to background view
		m_Window.setView(m_BGRightView);
		//Draw the background
		m_Window.draw(m_BackgroundSprite);
		//Switch to right view
		m_Window.setView(m_RightView);

		//Draw Thomas
		m_Window.draw(m_Thomas.getSprite());
		//Draw Bob
		m_Window.draw(m_Bob.getSprite());
	}

	//Draw the HUD
	//Switch to HUD view
	m_Window.setView(m_HUDView);

	//Show everything we have just drawn
	m_Window.display();
}