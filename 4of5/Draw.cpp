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
		//Draw level into view
		m_Window.draw(m_VALevel, &m_TextureFiles);
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
		m_Window.draw(m_VALevel, &m_TextureFiles);

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
		m_Window.draw(m_VALevel, &m_TextureFiles);

		//Draw Thomas
		m_Window.draw(m_Thomas.getSprite());
		//Draw Bob
		m_Window.draw(m_Bob.getSprite());
	}

	//Draw the HUD
	m_Window.draw(m_Hud.getLevel());
	m_Window.draw(m_Hud.getTime());
	if (!m_IsPlaying)
	{
		m_Window.draw(m_Hud.getMesage());
	}

	//Switch to HUD view
	m_Window.setView(m_HUDView);

	//Show everything we have just drawn
	m_Window.display();
}