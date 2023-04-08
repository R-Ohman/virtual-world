#pragma once
#ifndef _HOGWEED_H_
#define _HOGWEED_H_

#include <stdio.h>
#include "Plant.h"

class Hogweed : public Plant {
public:
    Hogweed() = default;
    Hogweed(World* currentWorld, unsigned posX = -1, unsigned posY = -1, unsigned age = 0);
    void draw() override;
    string getName() override;
    Organism* createClone(unsigned x, unsigned y) override;
    ~Hogweed() override;
};

#endif