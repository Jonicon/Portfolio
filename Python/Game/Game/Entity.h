#pragma once

// TODO: graphics component 

#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "GraphicsComponent.h"

enum nextMove;

class Entity
{
private:
	InputComponent*		input;
	PhysicsComponent*	physics;
	GraphicsComponent*	graphics;
	nextMove			nextMove_;
	int					x, y;
	int					velocity;


public:
	Entity(void);
	Entity( InputComponent* input_, 
			PhysicsComponent* physics_,
			GraphicsComponent* graphics_);
	~Entity(void);

	void update();
	void move();
	void setX(int x);
	void setY(int y);
	int const getX();
	int const getY();
};

