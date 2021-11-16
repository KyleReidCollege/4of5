#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

class Engine
{
private:
#pragma region Texture Holder
	TextureHolder th;
	const int TILE_SIZE = 50;
	const int VERT_IN_QUAD = 4;
#pragma endregion

	//The force	pushing the characters down
	const int GRAVITY = 300;

	sf::RenderWindow m_Window;

	sf::View m_BGMainView;
	sf::View m_BGLeftView;
	sf::View m_BGRightView;
	sf::View m_HUDView;

	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

#pragma region Booleans
	//True Booleans
	bool m_IsCharacter1Selected = true;
	bool m_NewLevelRequired = true;

	//False Booleans
	bool m_IsPlaying = false;
	bool m_IsSplitScreen = false;
#pragma endregion

	float m_TimeRemaining = 10;
	sf::Time m_GameTimeTotal;

	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	Engine();
	void run();
};

#endif ENGINE_H