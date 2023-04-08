#include "Human.h"

Human::Human(World* world, unsigned posX, unsigned posY, unsigned age)
	: Animal(world, 5, 4, posX, posY, age)
{
}

void Human::draw()
{
	printf(" H ");
}

void Human::action()
{
	this->age++;
	char userMove;
	unsigned* posX = &this->position[0], *posY = &this->position[1];
	unsigned newPosition[2] = { *posX, *posY };
	printf("Move (arrows) or use special ability (r):\n");
	printf("Human position(%d, %d)\n", *posX, *posY);
	while (true) {
		userMove = getchar();
		if (userMove == 'a' && *posX > 0) {
			newPosition[0] -= 1;
			break;
		}
		else if (userMove == 'd' && *posX < world->getWidth() - 1) {
			newPosition[0] += 1;
			break;
		}
		else if (userMove == 'w' && *posY > 0) {
			newPosition[1] -= 1;
			break;
		}
		else if (userMove == 's' && *posY < world->getHeight() - 1) {
			newPosition[1] += 1;
			break;
		}
		else if (userMove == 'r') {
			this->specialAbility();
			break;
		}
	}
	world->entitiesField[*posX][*posY] = nullptr;
	if (world->entitiesField[newPosition[0]][newPosition[1]] != nullptr) {
		collision(world->entitiesField[newPosition[0]][newPosition[1]]);
	} 
	else {
		*posX = newPosition[0];
		*posY = newPosition[1];
		world->entitiesField[*posX][*posY] = this;
	}
}

string Human::getName()
{
	return "Human";
}

void Human::specialAbility()
{
}

Organism* Human::createClone(unsigned x, unsigned y)
{
	return new Human(world, x, y);
}

Human::~Human()
{
}
