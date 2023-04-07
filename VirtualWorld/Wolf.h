#pragma once

#include <stdio.h>
#include "Animal.h"

class Wolf : public Animal {
public:
    Wolf(World* currentWorld, int posX, int posY, int age, bool newBorn);
    void draw() override;
    string getName() override;
    Organism* clone(int posX, int posY) override;
    ~Wolf() override;
};
