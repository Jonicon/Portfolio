#include "World.h"

World::World() { 
	//TODO: some day, decouple this entity creation
	auto player = new Entity( new InputComponent, new PhysicsComponent, new GraphicsComponent( SDL_LoadBMP("player.bmp") ) );
	auto blob = new Entity( new InputComponent, new PhysicsComponent, new GraphicsComponent( SDL_LoadBMP("blob.bmp") ) );
	entities.push_back(*player);
	entities.push_back(*blob);
}


World::~World(void) {

}

