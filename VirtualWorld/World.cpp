#include "World.h"


Entities::Entities(unsigned allocatedSize) : allocatedSize(allocatedSize), size(0)
{
	head = new Node();
	head->entity = NULL;
	head->next = NULL;
}

int Entities::getAllocSize()
{
    return this->allocatedSize;
}

int Entities::getSize()
{
    return this->size;
}

void Entities::add(Organism* entity)
{
    // Sprawdzenie czy jest wolne miejsce w ilosci organizmow
    if (size == allocatedSize) {
        printf("Entity lookup is full!\n");
        return;
    }

    // Dodanie nowego organizmu
    Node* newEntityNode = new Node;
    newEntityNode->entity = entity;
    newEntityNode->next = nullptr;

    Node* current = head;

    // Znalezienie miejsca dla nowego organizmu
    while (current->next != nullptr) {
        // sprawdzenie czy inicjatywa nowego organizmu jest większa od następnego organizmu
        if (entity->getInitiative() > current->next->entity->getInitiative()) {
            // jeżeli tak to koniec funkcji
            break;
        }
        // Sprawdzenie czy inicjatywy są równe
        else if (entity->getInitiative() == current->next->entity->getInitiative()) {
            // Jeżeli tak to sprawdza wiek
            if (entity->getAge() >= current->next->entity->getAge()) {
                //Jeżeli wiek jest większy lub równy to koniec funkcji
                break;
            }
        }
        current = current->next;
    }
    // Ustawienie nowego organizmu w kolejce
    newEntityNode->next = current->next;
    current->next = newEntityNode;
    // Zwiększenie currentSize
    this->size++;
}

void Entities::remove(Organism* entity)
{
	Node* current = head;
	Node* previous = nullptr;

	// Szukanie organizmu do usunięcia
	while (current->next != nullptr) {
		if (current->entity == entity) {
			break;
		}
		previous = current;
		current = current->next;
	}
    if (previous != nullptr) {
        previous->next = current->next;
    }
    // Usunięcie organizmu
	delete current;
	// Zmniejszenie currentSize
	this->size--;
}

Entities::~Entities()
{
}

World::World(unsigned w, unsigned h) : width(w), height(h)
{
    humanRegeneration = 0;
	turnNumber = 0;
    printf("World(%d,%d) initialized...\n", w, h);
    srand(time(NULL));

    // Zaalokowanie przestrzeni dla organizmów
    entitiesField = new Organism** [w];
    for (int i = 0; i < w; i++) {
        entitiesField[i] = new Organism* [h];
    }

    // Ustawienie pustego pola na każdej pozycji
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            entitiesField[i][j] = NULL;
        }
    }

    // Wezwanie lookupu
    entitiesList = new Entities(w * h);
    
	Human* human = new Human(this, 0, 0, 0);
	entitiesList->add(human);
	entitiesField[0][0] = human;
}


int World::getWidth()
{
    return this->width;
}

int World::getHeight()
{
    return this->height;
}

int World::getHumanRegeneration()
{
    return this->humanRegeneration;
}

int World::getTurnNumber()
{
    return this->turnNumber;
}

bool World::gameContinues()
{
    return entitiesList->getSize() < entitiesList->getAllocSize();
}

void World::drawWorld()
{
    printf("Drawing world...\n");

    unsigned x, y, number = 0;
    printf("Turn %d\n[xxx] ", turnNumber);

    for (x = 0; x < width; x++) {
        if (number <= 9) {
            printf("[00%d]", number);
        }
        else {
            printf("[0%d]", number);
        }
        number++;
    }
    number = 0;
    printf("\n");
    // Zakładam że liczby nie będą większe niz 99
    for (y = 0; y < height; y++) {
        if (number <= 9) {
            printf("[00%d] ", number);
        }
        else {
            printf("[0%d] ", number);
        }
        number++;

        for (x = 0; x < width; x++) {
             if (entitiesField[x][y] != NULL) {
                printf("[");
                entitiesField[x][y]->draw();
                printf("]");
            }
            else {
                printf("[   ]");
            }
        }
        printf("\n");
    }
    printf("Legend :\n[A - Antelope][B - Belladonna][F - Fox]\n[# - Grass][G - Guarana][& - Hogweed]\n[<.> - Human][S - Sheep][D - Dandelion]\n[T - Turtle][W - Wolf]\n");
}

void World::makeTurn()
{
    printf("Processing turn %d...\n", turnNumber);

    Node* current = entitiesList->head->next;
    // Obniżenie cooldownu specjalnej umiejętności
    if (humanRegeneration > 0) {
        humanRegeneration--;
    }

    while (current != NULL) {
        // Nowo narodzone organizmy się nie ruszają
        current->entity->action();
        current = current->next;
    }
    turnNumber++;
}

void World::placeRandom(Organism* entity)
{
    // Ta funkcja spróbuje położyć organizm na pustym miejscu
    // Jeżeli wybrane miejsce będzie zajęte to organism się nie stworzy
    int newPosition[2];
    newPosition[0] = rand() % getWidth();
    newPosition[1] = rand() % getHeight();

    if (entitiesField[newPosition[0]][newPosition[1]] == NULL) {
        // Jeżeli się udało
        entity->setX(newPosition[0]);
        entity->setY(newPosition[1]);
        entitiesField[newPosition[0]][newPosition[1]] = entity;
        entitiesList->add(entity);
    }
    else {
        // Jeżeli się nie udało
        delete entity;
    }
}

void World::saveWorld()
{
    
}

World::~World()
{
    
}
