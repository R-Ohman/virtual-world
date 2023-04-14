#include "World.h"
#include <windows.h>


Entities::Entities(unsigned allocatedSize) : allocatedSize(allocatedSize), size(0)
{
	head = new Node();
	head->entity = nullptr;
	head->next = nullptr;
}


unsigned Entities::getAllocSize() const
{
	return this->allocatedSize;
}


unsigned Entities::getSize() const
{
	return this->size;
}


void Entities::setSize(unsigned size)
{
	this->size = size;
}


void Entities::add(Organism* entity)
{
	if (size >= allocatedSize) {
		printf("Entity lookup is full!\n");
		return;
	}

	Node* newEntityNode = new Node;
	newEntityNode->entity = entity;
	newEntityNode->next = nullptr;

	Node* current = head;

	// Look for the place to sort by initiative (and then by age)
	while (current->next != nullptr) {
		if (current->next->entity == entity) {
			// If organism is already in the list
			return;
		}
		// If initiative is higher than the next one, place is found
		if (entity->getInitiative() > current->next->entity->getInitiative()) {
			break;
		}
		else if (entity->getInitiative() == current->next->entity->getInitiative()
			&& entity->getAge() >= current->next->entity->getAge()
			) {
			// Sort by age if initiative is the same
			break;
		}
		current = current->next;
	}
	// Paste new entity node
	newEntityNode->next = current->next;
	current->next = newEntityNode;

	this->size++;
}


void Entities::remove(Organism* entity)
{
	Node* current = head;
	Node* previous = nullptr;

	// Look for node with entity to remove
	while (current != nullptr && current->entity != entity) {
		previous = current;
		current = current->next;
	}
	// If entity is not in the list
	if (current == nullptr) {
		return;
	}

	if (previous != nullptr) {
		previous->next = current->next;
	}
	else {
		// If entity is the first one in the list
		head = current->next;
	}

	if (entity->getName() == "Human") {
		// Human is dead, so the game is over
		dynamic_cast<Human*>(entity)->setStrength(0);
		std::cout << "GAME OVER: Human died!\n";
	}

	this->size--;
	delete entity;
}


Entities::~Entities()
{
}


World::World(unsigned w, unsigned h) : width(w), height(h), turnNumber(0)
{
	srand(time(NULL));

	// Allocate space for organisms
	entitiesField = new Organism * *[width];
	for (size_t i = 0; i < width; i++) {
		entitiesField[i] = new Organism * [height];
	}

	for (size_t i = 0; i < width; i++) {
		for (size_t j = 0; j < height; j++) {
			entitiesField[i][j] = nullptr;
		}
	}

	entitiesList = new Entities(width * height);
}


World::World(std::ifstream& loadFile)
{
	srand(time(NULL));
	// Read turn number and world dimensions
	loadFile >> turnNumber >> width >> height;
	printf("Saved world(%d,%d) initialized...\n", width, height);

	// Allocate space for organisms
	entitiesField = new Organism * *[width];
	for (size_t i = 0; i < width; i++) {
		entitiesField[i] = new Organism * [height];
	}

	for (size_t i = 0; i < width; i++) {
		for (size_t j = 0; j < height; j++) {
			entitiesField[i][j] = NULL;
		}
	}

	entitiesList = new Entities(width * height);


	// Create organisms using data from file
	// Organisms will be added to the world in the constructor
	string className;
	unsigned posX, posY, age, regeneration, strength;
	
	while (loadFile >> className) {
		loadFile >> posX >> posY >> age >> strength;
		if (className == "Antelope") {
			new Antelope(this, posX, posY, age, strength);
		}
		else if (className == "Belladonna") {
			new Belladonna(this, posX, posY, age, strength);
		}
		else if (className == "Dandelion") {
			new Dandelion(this, posX, posY, age, strength);
		}
		else if (className == "Fox") {
			new Fox(this, posX, posY, age, strength);
		}
		else if (className == "Grass") {
			new Grass(this, posX, posY, age, strength);
		}
		else if (className == "Guarana") {
			new Guarana(this, posX, posY, age, strength);
		}
		else if (className == "Hogweed") {
			new Hogweed(this, posX, posY, age, strength);
		}
		else if (className == "Human") {
			loadFile >> regeneration;
			new Human(this, posX, posY, age, regeneration, strength);
		}
		else if (className == "Sheep") {
			new Sheep(this, posX, posY, age, strength);
		}
		else if (className == "Turtle") {
			new Turtle(this, posX, posY, age, strength);
		}
		else if (className == "Wolf") {
			new Wolf(this, posX, posY, age, strength);
		}
	}
}


unsigned World::getWidth() const
{
	return this->width;
}


unsigned World::getHeight() const
{
	return this->height;
}


unsigned World::getTurnNumber() const
{
	return this->turnNumber;
}


void World::placeRandom(Organism* entity)
{
	// Place organism on random position
	do {
		// Generate random position while it's not empty
		entity->setX(rand() % getWidth());
		entity->setY(rand() % getHeight());
	} while (entitiesField[entity->getX()][entity->getY()] != nullptr);

	entitiesField[entity->getX()][entity->getY()] = entity;
	entitiesList->add(entity);
}


bool World::gameContinues() const
{
	// iterate every organism
	Node* current = entitiesList->head;
	for (size_t i = 0; i < entitiesList->getSize(); i++) {
		if (dynamic_cast<Human*>(current->entity)) {
			return dynamic_cast<Human*>(current->entity)->getStrength() > 0;
		}
		current = current->next;
	}
	return false;
}


void World::drawHeader() const
{
	// Print information about organisms

	printf("\t\t\t\tFAQ\n");
	printf("Organism\tDesignation\tInitiative\t\tFeature\n");
	printf("Antelope\tA\t\t4\t\tDouble move, 50%% to escape from fight\n");
	printf("Fox\t\tF\t\t7\t\tDoesn't move to danger place\n");
	printf("Human\t\tH\t\t4\t\tMoved by user\n");
	printf("Sheep\t\tS\t\t7\n");
	printf("Wolf\t\tW\t\t5\n");
	printf("Belladonna\tB\t\t0\t\tThe animal that ate it, dies\n");
	printf("Dandelion\td\t\t0\t\t3 attempts to spread\n");
	printf("Grass\t\tg\t\t0\n");
	printf("Guarana\t\tG\t\t0\t\tIncreases the strength of of the animal that has eaten it, by 3\n");
	printf("Hogweed\t\tH\t\t0\t\tKills all animals in neighborhood\n");
}


void World::drawWorld() const
{
	this->drawHeader();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	/*
	// Print all Organisms
	int counter = 1;
	for (size_t y = 0; y < height; y++) {
		for (size_t x = 0; x < width; x++) {
			if (entitiesField[x][y] != nullptr) {
				std::cout << counter++ << ".\t";
				std::cout << entitiesField[x][y]->getName() << " (";
				std::cout << entitiesField[x][y]->getX() << ", " << entitiesField[x][y]->getY() << ")\n";
			}
		}
	}
	std::cout << std::endl;

	counter = 1;
	Node* node = entitiesList->head->next;
	while (node != nullptr && node->entity != nullptr) {
		std::cout << counter++ << "/" << entitiesList->getSize() << ".\t";
		std::cout << node->entity->getName() << " (";
		std::cout << node->entity->getX() << ", " << node->entity->getY() << ")\n";
		node = node->next;
	}
	*/

	unsigned x, y, number = 0;

	// Print the firts line with numbers
	printf("\n\t\tTurn %d\n\t\t     ", turnNumber);
	for (x = 0; x < width; x++) {
		if (number <= 9) {
			printf("[00%d]", number);
		}
		else if (number <= 99) {
			printf("[0%d]", number);
		}
		else {
			printf("[%d]", number);
		}
		number++;
	}

	number = 0;
	printf("\n");
	// Print the dest of the world
	for (y = 0; y < height; y++) {
		std::cout << "\t\t";

		if (number <= 9) {
			printf("[00%d]", number);
		}
		else if (number <= 99) {
			printf("[0%d]", number);
		}
		else {
			printf("[%d]", number);
		}
		number++;

		for (x = 0; x < width; x++) {
			// Set color of the text for different columns
			if (x % 2) {
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
			}
			else {
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			}
			
			// Draw organism
			if (entitiesField[x][y] != nullptr) {
				// Human - white text
				if (dynamic_cast<Human*>(entitiesField[x][y]) != nullptr) {
					SetConsoleTextAttribute(hConsole, 15);
				}
				else if (dynamic_cast<Animal*>(entitiesField[x][y]) != nullptr) {
					// Animal - red text
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				}
				else {
					// Plant - green text
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				printf("[");
				entitiesField[x][y]->draw();
				printf("]");
			}
			else {
				printf("[   ]");
			}
			// White color
			SetConsoleTextAttribute(hConsole, 15);
		}
		printf("\n");
	}
	
	// White color
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	printf("\tLEGEND :\n\t[Axx: X - first letter of animal's name, xx - its power][(A): A - first letter of plant's name]\n");
}


void World::makeTurn()
{
	// Action for every organism
	
	Node* current = entitiesList->head->next;
	while (current != nullptr) {
		// Organism is new - it can't move
		if (current->entity->getAge() == 0) {
			current->entity->setAge(current->entity->getAge() + 1);
		}
		else {
			current->entity->action();
		}
		current = current->next;
	}
	this->turnNumber++;
}


void World::saveWorld()
{
	std::ofstream fileBackup;
	fileBackup.open("worldState.txt", std::ios::out);
	
	if (!fileBackup) {
		printf("Problems with opening the file. Couldn't save the world.\n");
		return;
	}
	fileBackup << turnNumber << " " << width << " " << height << "\n";
	
	// Write all organisms with its parameters
	Node* current = entitiesList->head->next;
	while (current != nullptr && current->entity != nullptr) {
		fileBackup << current->entity->getName() << " " << current->entity->getX() << " " << current->entity->getY() << " " << current->entity->getAge() << " " << current->entity->getStrength() << "\n";
		
		if (dynamic_cast<Human*>(current->entity) != nullptr) {
			fileBackup << dynamic_cast<Human*>(current->entity)->getRegeneration() << "\n";
		}
		current = current->next;
	}
	
	fileBackup.close();
	printf("World state saved to worldState.txt.\n");
}

World::~World()
{
	try {
		for (unsigned x = 0; x < width; x++) {
			for (unsigned y = 0; y < height; y++) {
				if (entitiesField[x][y] != nullptr) {
					delete entitiesField[x][y];
				}
			}
		}
		
		delete entitiesList;
	}
	catch (std::exception&) {
		printf("Error while deleting the world.\n");
	}
}
