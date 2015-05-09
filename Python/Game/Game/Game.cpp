#include "Game.h"


Game::Game(World* world_) : world(world_)
{
}


Game::~Game(void)
{
}


void Game::GameLoop() {
	isRunning = true;
	while (isRunning){
		while( SDL_PollEvent(&event) != 0 ){
			if (event.type == SDL_QUIT)
				isRunning = false;
		}
		// get player input
		// update all entites
		for ( auto entity : world->entities ) {
			entity.update();
		}
		// render everything
	}
}

