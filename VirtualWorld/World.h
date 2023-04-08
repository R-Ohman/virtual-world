#pragma once
#ifndef _WORLD_H_
#define _WORLD_H_

#include "Organism.h"     // Organizm

#include "Animal.h"       // Zwierzę

#include "Human.h"        // Człowiek
#include "Sheep.h"        // Owca
#include "Wolf.h"         // Wilk
#include "Fox.h"          // Lis
#include "Turtle.h"       // Żółw
#include "Antelope.h"     // Antylopa

#include "Plant.h"        // Roślina
#include "Grass.h"        // Trawa
#include "Dandelion.h"    // Mlecz
#include "Guarana.h"      // Guarana
#include "Belladonna.h"   // Wilcza jagoda
#include "Hogweed.h"      // Barszcz Sosnowskiego

#include <iostream>     // input output stream
#include <fstream>      // input output file
#include <time.h>       // srand time NULL
#include <typeinfo>     // typeid()

class Organism;
using std::string;


// Tury organizmów odbywają się w ten sposób, że przeskakujemy po każdym kolejnym organiźmie i wykonujemy jego ruch i/lub akcję
// Organizmy ustawiają się w kolejce wtedy gdy są tworzone
struct Node {
    Organism* entity;
    Node* next;
};


class Entities {
private:
    int allocatedSize;
    int size = 0;
public:
    Entities(unsigned allocatedSize);
    Node* head;
    int getAllocSize();
    int getSize();
    void add(Organism* entity);
    void remove(Organism* entity);
    ~Entities();
};


class World {
private:
    unsigned width, height;
    unsigned turnNumber;
    int humanRegeneration;
    //bool gameStatus;
public:
    World(unsigned w, unsigned h);                                // Konstruktor nowego świata defaultowego
    //World(unsigned w, unsigned h, std::ifstream& loadFile);       // Konstruktor świata zapisanego w pliku

    int getWidth();
    int getHeight();
    int getHumanRegeneration();
    int getTurnNumber();
    //bool getGameStatus();
    //void setGameStatus();
    //void setHumanCooldown(int i);
    //void setTurn(int turn);

    bool gameContinues();

    // rysujSwiat()
    void drawWorld();
    // wykonajTure()
    void makeTurn();
    
    void placeRandom(Organism* entity);
    //void placeSpecific(Organism* entity, int axisX, int axisY);

    //void saveWorld();
    //World loadWorld();

    // Organizmy
    Organism*** entitiesField;  // wskaźnik na array dwu wymiarowy ze wskaźnikami
    Entities* entitiesList;

    ~World();
};

#endif