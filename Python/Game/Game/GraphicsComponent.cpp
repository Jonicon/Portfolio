#include "GraphicsComponent.h"


GraphicsComponent::GraphicsComponent( SDL_Surface* surf ) 
										: texture( surf ) {}


GraphicsComponent::~GraphicsComponent( void )
{
}
