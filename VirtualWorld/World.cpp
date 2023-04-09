#include "World.h"
#include <windows.h>

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

	//std::cout << "Add entity to lookup: " << typeid(*entity).name() << ". New size : " << size << " .\n";

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
        //std::cout << "Remove entity from lookup: " << typeid(*entity).name() << ". New size : " << size << " .\n";
        // Освобождение памяти, выделенной под элемент списка
        if (entity->getName() == "Human") {
            // GAME OVER
            this->size = unsigned(-1) / 2;
			std::cout << "GAME OVER: Human died!\n";
        }
        
        delete entity;
    }
}

Entities::~Entities()
{
} 

World::World(unsigned w, unsigned h) : width(w), height(h)
{
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

World::World(std::ifstream& loadFile)
{
    loadFile >> turnNumber >> width >> height;
    printf("Saved world(%d,%d) initialized...\n", width, height);
    srand(time(NULL));

    // Zaalokowanie przestrzeni dla organizmów
    entitiesField = new Organism **[width];
    for (int i = 0; i < width; i++) {
        entitiesField[i] = new Organism * [height];
    }

    // Ustawienie pustego pola na każdej pozycji
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            entitiesField[i][j] = NULL;
        }
    }

    // Wezwanie lookupu
    entitiesList = new Entities(width * height);

    Organism* newEntity;
    std::string className;
    
    int posX, posY, age;
    while (loadFile >> className) {
        loadFile >> posX >> posY >> age;
        if (className == "Antelope") {
			new Antelope(this, posX, posY, age);
        }
        else if (className == "Belladonna") {
            new Belladonna(this, posX, posY, age);
        }
		else if (className == "Dandelion") {
			new Dandelion(this, posX, posY, age);
		}
		else if (className == "Fox") {
			new Fox(this, posX, posY, age);
		}
		else if (className == "Grass") {
			new Grass(this, posX, posY, age);
		}
		else if (className == "Guarana") {
			new Guarana(this, posX, posY, age);
		}
		else if (className == "Hogweed") {
			new Hogweed(this, posX, posY, age);
		}
		else if (className == "Human") {
			new Human(this, posX, posY, age);
		}
		else if (className == "Sheep") {
			new Sheep(this, posX, posY, age);
		}
		else if (className == "Turtle") {
			new Turtle(this, posX, posY, age);
		}
		else if (className == "Wolf") {
			new Wolf(this, posX, posY, age);
		}
    }
}

int World::getHeight()
{
    return this->height;
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
    printf("Drawing world...\n");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    unsigned x, y, number = 0;
    printf("\tTurn %d\n\t\t[xxx] ", turnNumber);
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
        std::cout << "\t\t";
        if (number <= 9) {
            printf("[00%d] ", number);
        }
        else {
            printf("[0%d] ", number);
        }
        number++;

        for (x = 0; x < width; x++) {
            if (x % 2) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            }
            else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
            }
            
             if (entitiesField[x][y] != nullptr) {
                 // Czlowiek - bialy tekst
                 if (dynamic_cast<Human*>(entitiesField[x][y]) != nullptr) {
                     SetConsoleTextAttribute(hConsole, 15);
                 }
                 else if (dynamic_cast<Animal*>(entitiesField[x][y]) != nullptr) {
					 // Zwierze - czerwony tekst
                     SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                 }
                 else {
					 // Roslina - zielony tekst
                     SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                 }
                printf("[");
                entitiesField[x][y]->draw();
                printf("]");
                SetConsoleTextAttribute(hConsole, 15);
            }
            else {
                printf("[   ]");
            }
        }
        printf("\n");
    }
    // Bialy tekst
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    printf("Legend :\n[Axx: X - first letter of animal's name, xx - its power][(A): A - first letter of plant's name]\n");
}

void World::makeTurn()
{
    printf("Processing turn %d...\n", turnNumber);

    Node* current = entitiesList->head->next;

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

void World::saveWorld()
{
    std::ofstream fileBackup;
    fileBackup.open("backupWorld.txt", std::ios::out);
    if (!fileBackup) {
        printf("Problems with opening the file. Couldn't save the world.\n");
        return;
    }
    else {
        fileBackup << turnNumber << "\n";
        fileBackup << width << " " << height << "\n";
        Node* current = entitiesList->head->next;
        while (current != nullptr) {
            fileBackup << current->entity->getName() << " " << current->entity->getX() << " " << current->entity->getY() << " " << current->entity->getAge() << "\n";
            current = current->next;
        }
        fileBackup.close();
        printf("State of the world was successfully saved to the file.\n");
    }
}

World::~World()
{
	for (unsigned x = 0; x < width; x++) {
		for (unsigned y = 0; y < height; y++) {
			if (entitiesField[x][y] != nullptr) {
				delete entitiesField[x][y];
			}
		}
	}
	delete entitiesList;
}
