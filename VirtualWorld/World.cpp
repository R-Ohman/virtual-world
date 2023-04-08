#include "World.h"

Entities::Entities(unsigned allocatedSize) : allocatedSize(allocatedSize), size(0)
{
	head = new Node();
	head->entity = nullptr;
	head->next = nullptr;
}

int Entities::getAllocSize()
{
    return this->allocatedSize;
}

int Entities::getSize()
{
    return this->size;
}

void Entities::setSize(unsigned size)
{
    this->size = size;
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
    // Sortuje po inicjatywie i wieku
    // Znalezienie miejsca dla nowego organizmu
    while (current->next != nullptr) {
        if (current->next->entity == entity) {
            return;
        }
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

	std::cout << "Add entity to lookup: " << typeid(*entity).name() << ". New size : " << size << " .\n";

}

void Entities::remove(Organism* entity)
{
    Node* current = head;
    Node* previous = nullptr;

    // Поиск элемента, содержащего указатель на удаляемый объект
    while (current != nullptr && current->entity != entity) {
        previous = current;
        current = current->next;
    }

    // Если элемент найден
    if (current != nullptr) {
        // Обновление указателя previous на следующий элемент списка
        if (previous != nullptr) {
            previous->next = current->next;
        }
        else {
            head = current->next;
        }

        // Уменьшение размера списка
        this->size--;
        std::cout << "Remove entity from lookup: " << typeid(*entity).name() << ". New size : " << size << " .\n";
        // Освобождение памяти, выделенной под элемент списка
        delete entity;
    }
}

Entities::~Entities()
{
} 

World::World(unsigned w, unsigned h) : width(w), height(h)
{
    humanRegeneration = 5;
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
            entitiesField[i][j] = nullptr;
        }
    }

    // Wezwanie lookupu
    entitiesList = new Entities(w * h);
    
	this->placeRandom(new Human(this));

    this->placeRandom(new Antelope(this));
    this->placeRandom(new Antelope(this));

    this->placeRandom(new Wolf(this));
    this->placeRandom(new Wolf(this));
    
    this->placeRandom(new Turtle(this));
    this->placeRandom(new Turtle(this));

	this->placeRandom(new Sheep(this));
	this->placeRandom(new Sheep(this));
    
    this->placeRandom(new Fox(this));
    this->placeRandom(new Fox(this));

    this->placeRandom(new Guarana(this));
    this->placeRandom(new Guarana(this));
    
    this->placeRandom(new Grass(this));
    this->placeRandom(new Grass(this));
    
    this->placeRandom(new Hogweed(this));
    this->placeRandom(new Hogweed(this));
    
    this->placeRandom(new Dandelion(this));
    this->placeRandom(new Dandelion(this));

    this->placeRandom(new Belladonna(this));
    this->placeRandom(new Belladonna(this));
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
    printf("Legend :\n[A - Antelope][(B) - Belladonna][F - Fox]\n[(g) - Grass][(G) - Guarana][(H) - Hogweed]\n[H - Human][S - Sheep][(D) - Dandelion]\n[T - Turtle][W - Wolf]\n");
}

void World::makeTurn()
{
    printf("Processing turn %d...\n", turnNumber);

    Node* current = entitiesList->head->next;
    // Obniżenie cooldownu specjalnej umiejętności
    if (humanRegeneration > 0) {
        humanRegeneration--;
    }

    while (current != nullptr) {
        // Nowo narodzone organizmy się nie ruszają
        if (current->entity->getAge() == 0) {
			current->entity->setAge(current->entity->getAge() + 1);
        }
        else {
            current->entity->action();
        }
        current = current->next;
    }
    turnNumber++;
}

void World::placeRandom(Organism* entity)
{
    // Ta funkcja spróbuje położyć organizm na pustym miejscu
    // Jeżeli wybrane miejsce będzie zajęte to organism się nie stworzy
    do {
		entity->setX(rand() % getWidth());
		entity->setY(rand() % getHeight());
	} while (entitiesField[entity->getX()][entity->getY()] != nullptr);
	entitiesField[entity->getX()][entity->getY()] = entity;
	entitiesList->add(entity);
}

World::~World()
{
    
}
