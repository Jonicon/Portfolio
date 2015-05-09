#pragma once
#include <vector>
#include "Entity.h"
#define MAX_ENTITIES 1000

class World
{
private:

public:
	World();
	~World(void);

	std::vector<Entity> entities;
};

