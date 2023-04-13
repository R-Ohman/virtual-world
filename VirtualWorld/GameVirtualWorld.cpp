#include "GameVirtualWorld.h"


void GameVirtualWorld::setOrganisms()
{
    world->placeRandom(new Human(world));

	// Place organisms in groups of 10
    for (int i = 0; i <= world->getWidth() * world->getHeight() / WORLD_SIZE_FOR_ORGANISMS_GROUP; i++)
    {
        world->placeRandom(new Antelope(world));

        world->placeRandom(new Wolf(world));

        world->placeRandom(new Turtle(world));

        world->placeRandom(new Sheep(world));

        world->placeRandom(new Fox(world));

        world->placeRandom(new Guarana(world));

        world->placeRandom(new Grass(world));

        world->placeRandom(new Hogweed(world));

        world->placeRandom(new Dandelion(world));

        world->placeRandom(new Belladonna(world));
    }    
}


void GameVirtualWorld::drawMenu()
{
    system("cls");
    printf("\t|-------------------------|\n");
    printf("\t| Ruslan Rabadanov 196634 |\n");
    printf("\t|  Press arrows to move   |\n");
    printf("\t|   %c - special ability   |\n", ACTIVATE_SUPERPOWER_BUTTON);
    printf("\t|   %c - save the game     |\n", SAVE_WORLD_BUTTON);
    printf("\t|  - - - - - - - - - - -  |\n");
    printf("\t|   1 - Start new game    |\n");
    printf("\t|   2 - Load last save    |\n");
    printf("\t|   other - Quit          |\n");
    printf("\t| - - - - - - - - - - - - |\n");
    printf("\t|   Choose the option : ");
}


void GameVirtualWorld::game() {
    while (world->gameContinues()) {
        system("cls");
        world->drawWorld();
        world->makeTurn();
        printf("\nAny key to continue [%c - save, %c - exit]\n", SAVE_WORLD_BUTTON, EXIT_GAME_BUTTON);
        
        int playerInput = _getch();
        if (playerInput == SAVE_WORLD_BUTTON) {
            world->saveWorld();
            playerInput = _getch();
        }
        else if (playerInput == EXIT_GAME_BUTTON) {
            break;
        }
    }
    // Game over
    system("cls");
    world->drawWorld();
    std::cout << "GAME OVER\n";
    std::cout << "Press any key to exit\n";
    _getch();
}


void GameVirtualWorld::start()
{
    // Draw start menu
	this->drawMenu();
    
    unsigned userOption = 0, width, height;
    std::cin >> userOption;

    if (userOption == 1) {
        printf("\t| New world size(w h) : ");
        do {
            std::cin >> width >> height;
		} while (width * height < ORGANISMS_NUMBER + 1);      // Minimum number of slots for organisms
        world = new World(width, height);
		// Add organisms to the created world
        this->setOrganisms();
    }
    else if (userOption == 2) {
        std::ifstream loadFile;
        loadFile.open("worldState.txt", std::ios::in);
        if (!loadFile) {
            printf("There is no saved world.\n");
            return;
        }
        world = new World(loadFile);
    }
    else {
        return;
    }
    
	// World is ready, start the game
    this->game();
}

GameVirtualWorld::~GameVirtualWorld()
{
    delete world;
}
