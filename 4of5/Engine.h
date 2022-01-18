#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "LevelManager.h"
#include "SoundManager.h"
#include "Thomas.h"
#include "Bob.h"

using namespace sf;

class Engine
{
private:

	//The texture holder
	TextureHolder th;

	//Thomas and his friend, Bob
	Thomas m_Thomas;
	Bob m_Bob;

	//A class reference to manage the levels
	LevelManager m_LM;

	//A class reference to manage sounds
	SoundManager m_SM;


	const int TILE_SIZE = 50;
	const int VERT_IN_QUAD = 4;


	//The force	pushing the characters down
	const int GRAVITY = 300;

	RenderWindow m_Window;

#pragma region Views
	//The main views
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	//Three view for the background and  and one HUD view
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;
	View m_HUDView;
#pragma endregion

	//Background sprite and texture
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

#pragma region Booleans
	//True Booleans
	//Is character 1 or 2 the current focus?
	bool m_IsCharacter1Selected = true;
	//Is it time for a new/first level?
	bool m_NewLevelRequired = true;

	//False Booleans
	//Is the game currently playing?
	bool m_IsPlaying = false;
	//Is the game in split screen mode?
	bool m_IsSplitScreen = false;
#pragma endregion

	//Time left in current level
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	//Vertex array for the level tiles
	VertexArray m_VALevel;

	//The 2D array with the map for the level
	int** m_ArrayLevel = NULL;

	//Texture for the level tiles
	Texture m_TextureFiles;

	vector <Vector2f> m_FireEmitters;

#pragma region Private Functions
	//Private function for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();
	void loadLevel();
	void populateEmitters(vector<Vector2f>& vSoundEmitters, int** arrayLevel);
	bool detectCollisions(PlayableCharacter& character);
#pragma endregion

public:
	//The Engine constructor
	Engine();
	//Run will call all the private functions
	void run();
};

#endif ENGINE_H