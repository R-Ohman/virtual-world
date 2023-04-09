#include "GameVirtualWorld.h"

void GameVirtualWorld::drawMenu()
{
    system("cls");
    printf("         | Ruslan Rabadanov 196634 |\n");
    printf("         |       Keys to move      |\n");
    printf("         |   w - up     s - down   |\n");
    printf("         |   a - left   d - right  |\n");
    printf("         |   r - special ability   |\n");
    printf("         |   x - save the game     |\n");
    printf("         |  - - - - - - - - - - -  |\n");
    printf("         |   1 - Start new game    |\n");
    printf("         |   2 - Load last save    |\n");
    printf("         |   3 - Quit              |\n");
    printf("         | - - - - - - - - - - - - |\n");
    printf("         |   Choose the option : ");
}


void GameVirtualWorld::game() {
    while (world->gameContinues()) {
        char playerInput;
        system("cls");
        world->drawWorld();
        world->makeTurn();
        // Jednocześnie służy to jako przerwa między narysowaniem kolejne tury
        // oraz zapis i załadowanie świata
        printf("Any key to continue [x - save, q - exit]\n");
        playerInput = getchar();
        playerInput = getchar();
        if (playerInput == 'x') {
            world->saveWorld();
            playerInput = getchar();
        }
        else if (playerInput == 'q') {
            break;
        }
    }
    // Koniec gry, pokaz świata
    system("cls");
    world->drawWorld();
}

void GameVirtualWorld::start()
{
	this->drawMenu();
    unsigned userOption = 0, playerInput, width, height;
    std::cin >> userOption;

    if (userOption == 1) {
        printf("         | New world size (w h): ");
        std::cin >> width >> height;
        // Konstruktor normalnego świata
        world = new World(width, height);
    }
    else if (userOption == 2) {
        std::ifstream loadFile;
        loadFile.open("backupWorld.txt", std::ios::in);
        if (!loadFile) {
            printf("There is no saved world.\n");
            exit(1);
        }
        // Konstruktor zapisanego świata
        world = new World(loadFile);
    }
    else {
        exit(1);
    }
    this->game();
    std::cout << "GAME OVER\n";
	std::cout << "Press any key to exit\n";
	getchar();
}

GameVirtualWorld::~GameVirtualWorld()
{
    delete world;
}
