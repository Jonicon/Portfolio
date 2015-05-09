#include <iostream>
#include "SDL.h"
#include "Game.h"


int main () {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = NULL;
	Game game(new World);

	window = SDL_CreateWindow("Game", 200, 200, 600, 400, SDL_WINDOW_SHOWN);

	if (window == NULL) 
		std::cout << "Window was not created properly: " << SDL_GetError();  

	game.GameLoop();
	return 0;
}
