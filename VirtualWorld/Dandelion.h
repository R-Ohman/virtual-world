#pragma once
#ifndef _DANDELION_H_
#define _DANDELION_H_

#include <stdio.h>
#include "Plant.h"

class Dandelion : public Plant {
public:
    Dandelion() = default;
    Dandelion(World* currentWorld, unsigned posX = 0, unsigned posY = 0, unsigned age = 0);
    void draw() override;
    void action() override;
    string getName() override;
    Organism* createClone(unsigned x, unsigned y) override;
    ~Dandelion() override;
};

#endif