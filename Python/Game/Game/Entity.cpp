#include "Entity.h"

Entity::Entity(void){

}


Entity::Entity( InputComponent* input_, 
				PhysicsComponent* physics_,
				GraphicsComponent* graphics_ ) 		
				: input(input_), physics(physics_), graphics(graphics_),
				  x(64), y(64), velocity(4)	{}


Entity::~Entity(void){
}

void Entity::update() {
		input->update();
		move();
		physics->update();
		graphics->update();
}

void Entity::move() {
	nextMove_ = input->getNextMove();
	switch (nextMove_){
		case UP:
			setY( -velocity );
			break;
		case DOWN:
			setY( velocity );
			break;
		case LEFT:
			setX( -velocity );
			break;
		case RIGHT:
			setX( velocity );
			break;
		case NONE:
			break;
		default:
			break;
		}
}

void Entity::setX( int x_ ) {
	x += x_;
}

void Entity::setY( int y_) {
	y += y_;
}

int const Entity::getX() {
	return x;
}

int const Entity::getY() {
	return y;
}

