#pragma once
#ifndef _TURTLE_H_
#define _TURTLE_H_

#include <stdio.h>
#include "Animal.h"

class Turtle : public Animal {
public:
    Turtle() = default;
    Turtle(World* currentWorld, unsigned posX = -1, unsigned posY = -1, unsigned age = 0);
    void draw() override;
    string getName() override;
    bool repulsedAttack(Organism* entity) override;
    Organism* createClone(unsigned x, unsigned y) override;
    ~Turtle() override;
};

#endif