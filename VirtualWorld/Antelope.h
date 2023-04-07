#ifndef Antelope_h
#define Antelope_h

#include "Animal.h"

#include <stdio.h>
#include "Animal.h"

// Każde zwierzę dziedziczy po klasie Zwierzę, które dziedziczy po Organiźmie
class Antelope : public Animal {
public:
    Antelope() = default;
    Antelope(World* currentWorld, int posX, int posY, int age, bool newBorn);
    int* pathFindNewField() override;
    void draw() override;
    string getName() override;
    void collision(Organism* collidingEntity) override;
    Organism* clone(int posX, int posY) override;
    ~Antelope() override;
};


#endif