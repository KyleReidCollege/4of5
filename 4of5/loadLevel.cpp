#include "Engine.h"

void Engine::loadLevel()
{
	m_IsPlaying = false;

	//Delete the previous allocated memory
	for (int h = 0; h < m_LM.getLevelSize().y; ++h)
	{
		delete[] m_ArrayLevel[h];
	}

	//Delete the entire array
	delete[] m_ArrayLevel;

	/*
	* Loading the next 2D array with the map for the level
	* and the repopulate the vertex array
	*/
	m_ArrayLevel = m_LM.nextLevel(m_VALevel);

	//How long is the new time limit?
	m_TimeRemaining = m_LM.getTimeLimit();

	//Spawn Thomas and Bob
	m_Thomas.spawn(m_LM.getStartPosition(), GRAVITY);
	m_Bob.spawn(m_LM.getStartPosition(), GRAVITY);

	m_NewLevelRequired = false;
}