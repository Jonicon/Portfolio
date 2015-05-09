#pragma once
#include "SDL.h"
class GraphicsComponent
{
private:
	const SDL_Surface* texture;
public:
	GraphicsComponent( SDL_Surface* surf );
	~GraphicsComponent( void );

	void update() {
	}
};

