#include "InputComponent.h"
#include "SDL.h"


InputComponent::InputComponent(void)
{
}


InputComponent::~InputComponent(void)
{
}


void InputComponent::update() {
	currentKeyStates = getKeyboard();
	if ( currentKeyStates[SDL_SCANCODE_UP] )
		nextMove_ = UP;
	else if ( currentKeyStates[SDL_SCANCODE_DOWN] )
		nextMove_ = DOWN;
	else if ( currentKeyStates[SDL_SCANCODE_LEFT] )
		nextMove_ = LEFT;
	else if ( currentKeyStates[SDL_SCANCODE_RIGHT] )
		nextMove_ = RIGHT;
	else
		nextMove_ = NONE;
}

const Uint8* InputComponent::getKeyboard(  ) {
	return SDL_GetKeyboardState( NULL );
}

const nextMove InputComponent::getNextMove() {
	return nextMove_;
}