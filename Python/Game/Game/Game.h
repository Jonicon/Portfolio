#pragma once
#include <vector>
#include "SDL.h"
#include "Entity.h"
#include "World.h"
class Game
{
private:
	bool isRunning;
	World* world;
	SDL_Event event;
public:
	Game(World* world_);
	~Game(void);

	void GameLoop();
};

