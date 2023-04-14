#include "Human.h"


Human::Human(World* world, unsigned posX, unsigned posY, unsigned age, unsigned regeneration, unsigned strength)
	: Animal(world, strength, HUMAN_INITIATIVE, posX, posY, age)
{
	this->humanRegeneration = regeneration;
}


void Human::draw() const
{
	// Max strength that can be displayed is 99
	string name = "H";
	if (this->strength < 100) {
		name += (strength / 10 + '0');
		name += (strength % 10 + '0');
	}
	else {
		// Human has strength 100+
		name = "-H-";
	}
	std::cout << name;
}


void Human::action()
{
	this->age++;
	
	if (this->humanRegeneration > 0) {
		this->humanRegeneration--;
	};
	
	int userMove;
	
	unsigned* const posX = &this->position[0], * const posY = &this->position[1];		// Variables for better readability
	
	unsigned newPosition[2] = { *posX, *posY };
	printf("\nHuman position(%d, %d)\n", *posX, *posY);
	printf("Move (arrows) or use special ability (%c):\n", ACTIVATE_SUPERPOWER_BUTTON);
	
	while (true) {
		userMove = _getch();					 // Read the first byte (224)
		if (userMove == 224) {
			userMove = _getch();				// Read the second byte (arrow key)
			if (userMove == LEFT_ARROW && *posX > 0) {
				newPosition[0] -= 1;
				break;
			}
			else if (userMove == RIGHT_ARROW && *posX < world->getWidth() - 1) {
				newPosition[0] += 1;
				break;
			}
			else if (userMove == UP_ARROW && *posY > 0) {
				newPosition[1] -= 1;
				break;
			}
			else if (userMove == DOWN_ARROW && *posY < world->getHeight() - 1) {
				newPosition[1] += 1;
				break;
			}
		}
		else if (userMove == ACTIVATE_SUPERPOWER_BUTTON) {

			if (humanRegeneration <= 0) {
				// Regeneration time is over, activate superpower
				printf("\tHuman's superpower is activated! Make a move.\n");
				humanRegeneration = REGENERATION_TIME + SUPERPOWER_TIME;
			}
			else if (humanRegeneration > REGENERATION_TIME) {
				printf("\tYou have already activated your superpower!\n");
				printf("\tIt will be disactivated in %d turns.\n", humanRegeneration - REGENERATION_TIME);
			}
			else {
				// It's the time of regeneration
				printf("\tYou will be able to activate it in %d turns!\n", humanRegeneration);
			}
		}
	}
	
	std::cout << "\nMOVING: " << this->getName() << " from (" << getX() << ", " << getY() << ") ";
	std::cout << "to (" << newPosition[0] << ", " << newPosition[1] << ").\n";

	// Remove human from old position
	world->entitiesField[*posX][*posY] = nullptr;
	
	if (humanRegeneration > REGENERATION_TIME) {
		// Superpower "holocaust", kill all naighbours
		this->specialAbility();
		
		// Move to new position
		*posX = newPosition[0];
		*posY = newPosition[1];
		world->entitiesField[*posX][*posY] = this;
		
		// Kill all neighbours
		this->specialAbility();
		return;
	}
	// If new position is occupied, collision
	if (world->entitiesField[newPosition[0]][newPosition[1]] != nullptr) {
		collision(world->entitiesField[newPosition[0]][newPosition[1]]);
	}
	else {
		// New position is empty, move
		*posX = newPosition[0];
		*posY = newPosition[1];
		world->entitiesField[*posX][*posY] = this;
	}
}


void Human::specialAbility()
{
	// Kill all neighbours (animals and plants)
	
	unsigned* const posX = &this->position[0], * const posY = &this->position[1];	// Variables for better readability
	
	// First iteration - check left and upper neighbours, second - right and lower
	for (int i = -1; i < 2; i += 2) {
		// Check if neighbouring position is in the bounds of the world
		if (*posX + i >= 0 && *posX + i < world->getWidth()) {
			// If neighbouring position is occupied, kill the entity
			if (world->entitiesField[*posX + i][*posY] != nullptr)
			{
				std::cout << "MURDER: " << getName() << " (" << *posX << ", " << *posY << ") ";
				std::cout << "murdered " << world->entitiesField[*posX + i][*posY]->getName() << " (" << *posX + i << ", " << *posY << ")\n";
				// Delete neighbour
				world->entitiesList->remove(world->entitiesField[*posX + i][*posY]);
				world->entitiesField[*posX + i][*posY] = nullptr;
			}
		}
		
		// Check if neighbouring position is in the bounds of the world
		if (*posY + i >= 0 && *posY + i < world->getHeight()) {
			// If neighbouring position is occupied, kill the entity
			if (world->entitiesField[*posX][*posY + i] != nullptr)
			{
				std::cout << "MURDER: " << getName() << " (" << *posX << ", " << *posY << ") ";
				std::cout << "murdered " << world->entitiesField[*posX + i][*posY]->getName() << " (" << *posX + i << ", " << *posY << ")\n";
				// Delete neighbour
				world->entitiesList->remove(world->entitiesField[*posX][*posY + i]);
				world->entitiesField[*posX][*posY + i] = nullptr;
			}
		}
	}
}

void Human::setStrength(unsigned strength)
{
	this->strength = strength;
}


string Human::getName() const
{
	return "Human";
}


Organism* Human::createClone(unsigned x, unsigned y) const
{
	return new Human(world, x, y);
}


int Human::getRegeneration()
{
	return this->humanRegeneration;
}


Human::~Human()
{
}
