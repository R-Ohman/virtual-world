#pragma once
#ifndef _GRASS_H_
#define _GRASS_H_

#include <stdio.h>
#include "Plant.h"

class Grass : public Plant {
public:
    Grass() = default;
    Grass(World* currentWorld, unsigned posX = 0, unsigned posY = 0, unsigned age = 0);
    void draw() override;
    string getName() override;
    Organism* createClone(unsigned x, unsigned y) override;
    ~Grass() override;
};

#endif