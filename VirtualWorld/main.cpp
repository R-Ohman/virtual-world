#include <iostream>
#include "World.h"

int main() {
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
    unsigned userOption, playerInput, width, height;
    std::cin >> userOption;

    //switch (userOption) {
    //case 1:
    //    printf("         | New world size : ");
    //    std::cin >> width >> height;
    //    // Konstruktor normalnego świata
    //    World newWorld(width, height);
    //    // Dopóki znajdujemy się na planszy
    //    while (newWorld.getGameStatus()) {
    //        system("cls");
    //        newWorld.drawWorld();
    //        newWorld.makeTurn();
    //        // Jednocześnie służy to jako przerwa między narysowaniem kolejne tury
    //        // oraz zapis i załadowanie świata
    //        printf("Any key to continue, x to save the game...\n");
    //        playerInput = getchar();
    //        if (playerInput == 'x') {
    //            newWorld.saveWorld();
    //            getchar();
    //            getchar();
    //        }
    //    }
    //    // Koniec gry, pokaz świata
    //    system("cls");
    //    newWorld.drawWorld();
    //    break;

    //case 2:
    //    std::ifstream loadFile;
    //    loadFile.open("backupWorld.txt", std::ios::in);
    //    if (!loadFile) {
    //        printf("There is no saved world.\n");
    //        exit(1);
    //    }
    //    int oldTurn, oldCooldown;
    //    loadFile >> oldTurn >> oldCooldown;
    //    loadFile >> width >> height;
    //    // Konstruktor zapisanego świata
    //    World savedWorld(width, height, loadFile);

    //    savedWorld.setTurn(oldTurn);                // Przywrócenie numeru tury
    //    savedWorld.setHumanCooldown(oldCooldown);   // Przywrócenie cooldownu specjalnej umiejętności

    //    while (savedWorld.getGameStatus()) {
    //        system("cls");
    //        savedWorld.drawWorld();
    //        savedWorld.makeTurn();
    //        playerInput = getchar();
    //        if (playerInput == 'x') {
    //            savedWorld.saveWorld();
    //            getchar();
    //            getchar();
    //        }
    //    }
    //    // Koniec gry, pokaz świata
    //    system("cls");
    //    savedWorld.drawWorld();
    //    break;

    //default:
    //    exit(1);
    //}

    // Koniec gry
    printf("GAME OVER\n");
    printf("Press any key to exit...");
    getchar();
    return 0;
};