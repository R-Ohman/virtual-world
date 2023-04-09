#pragma once
#ifndef _ANTELOPE_H_
#define _ANTELOPE_H_

#include <stdio.h>
#include "Animal.h"

// Każde zwierzę dziedziczy po klasie Zwierzę, które dziedziczy po Organiźmie
class Antelope : public Animal {
public:
    Antelope() = default;
    Antelope(World* currentWorld, unsigned posX = -1, unsigned posY = -1, unsigned age = 0);
    void draw() override;
    string getName() override;
    Organism* createClone(unsigned x, unsigned y) override;
    void collision(Organism* collidingEntity) override;
    unsigned* getNeighboringPosition() override;
    ~Antelope() override;
};


#endif