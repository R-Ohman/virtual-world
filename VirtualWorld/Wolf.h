#pragma once
#ifndef _WOLF_H_
#define _WOLF_H_

#include <stdio.h>
#include "Animal.h"

class Wolf : public Animal {
public:
    Wolf() = default;
    Wolf(World* currentWorld, unsigned posX = 0, unsigned posY = 0, unsigned age = 0);
    void draw() override;
    string getName() override;
    Organism* createClone(unsigned x, unsigned y) override;
    ~Wolf() override;
};

#endif