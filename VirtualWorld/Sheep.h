#pragma once
#ifndef _SHEEP_H_
#define _SHEEP_H_

#include <stdio.h>
#include "Animal.h"

class Sheep : public Animal {
public:
    Sheep() = default;
    Sheep(World* currentWorld, unsigned posX = 0, unsigned posY = 0, unsigned age = 0);
    void draw() override;
    string getName() override;
    Organism* createClone(unsigned x, unsigned y) override;
    ~Sheep() override;
};

#endif