#pragma once

#include <stdio.h>
#include "Animal.h"

class Sheep : public Animal {
public:
    Sheep(World* currentWorld, int posX, int posY, int age, bool newBorn);
    void draw() override;
    string getName() override;
    Organism* clone(int posX, int posY) override;
    ~Sheep() override;
};

