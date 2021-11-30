#ifndef BOB_H
#define BOB_H

#include "PlayableCharacter.h"

class Bob : public PlayableCharacter
{
public:
	//A constructor specific to Bob
	Bob();

	//The overridden input handler for Bob
	bool virtual handleInput();
};

#endif BOB_H