#ifndef PLAYABLE_CHARACTER_H
#define PLAYABLE_CHARACTER_H

#include <SFML/Graphics.hpp>

class PlayableCharacter
{
protected:
#pragma region Protected Variables
	//Of course we will need a sprite
	sf::Sprite m_Sprite;

	//How long does a jump last?
	float m_JumpDuration;

	//Is character currently jumping or falling?
	bool m_IsJumping;
	bool m_IsFalling;

	//Which directions is the character currently moving in
	bool m_LeftPressed;
	bool m_RightPressed;

	//How long has the jump lasted so far?
	float m_TimeThisJump;

	//Has the player just initiated a jump?
	bool m_JustJumped = false;
#pragma endregion

	//Private variables and functions come next

private:
#pragma region Private Variables
	//What is gravity?
	float m_Gravity;

	//How fast is the character?
	float m_Speed = 400;

	//Where is the player?
	sf::Vector2f m_Position;

	//Where are the character various body parts?
	sf::FloatRect m_Feet;
	sf::FloatRect m_Head;
	sf::FloatRect m_Right;
	sf::FloatRect m_Left;

	//And a texture
	sf::Texture m_Texture;
#pragma endregion

	//All out public functions will come next

public:
#pragma region Public Variables
	void spawn(sf::Vector2f startPosition, float gravity);

	//This is a pure virtual function
	bool virtual handleInput() = 0;

	//This class is now abstract and cannot be instantiated
	//Where is the player?
	sf::FloatRect getPosition();

	//A rectangle representing the position of different parts of the sprite
	sf::FloatRect getFeet();
	sf::FloatRect getHead();
	sf::FloatRect getRight();
	sf::FloatRect getLeft();

	//Send a copy of the sprite to main
	sf::Sprite getSprite();

	//Make the character stand firm
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();

	//Where is the centre of the character?
	sf::Vector2f getCentre();

	//We will call this function once every frame
	void update(float elapsedTime);
#pragma endregion

	//End of the class
};

#endif PLAYABLE_CHARACTER_H