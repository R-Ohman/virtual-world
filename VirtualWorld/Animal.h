#pragma once
#include <iostream>
#include <string>
#include "Organism.h"

using std::string;

// Zwierzęta dziedziczą po klasie Organizm
class Animal : public Organism {
public:
    Animal(World* currentWorld, int strength, int initiative, int pos_x, int pos_y, int age, bool newborn);
    bool doSpeciesMatch(Organism& entity);
    void breed();
    string getName() override = 0;         // Każde zwierzę ma inną nazwę
    void draw() override = 0;                   // Każde zwierzę jest inaczej oznaczane
    void action() override;                     // Każde zwierzę inaczej się zachowuje
    virtual void collision(Organism* collidingEntity);
    ~Animal();
};

