#pragma once
#ifndef _BELLADONNA_H_
#define _BELLADONNA_H_

#include <stdio.h>
#include <string>
#include "Plant.h"

class Belladonna : public Plant {
public:
    Belladonna() = default;
    Belladonna(World* currentWorld, unsigned posX = -1, unsigned posY = -1, unsigned age = 0);
    void draw() override;
    string getName() override;
    Organism* createClone(unsigned x, unsigned y) override;
    ~Belladonna() override;
};

#endif