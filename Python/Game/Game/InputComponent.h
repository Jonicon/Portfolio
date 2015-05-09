#include "SDL.h"
#pragma once


enum nextMove {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NONE
};

class InputComponent
{
private:
	nextMove		nextMove_;
	const Uint8*	currentKeyStates;

public:
	InputComponent(void);
	~InputComponent(void);

	void			update();
	const Uint8*	getKeyboard();
	const nextMove 		getNextMove();
};

