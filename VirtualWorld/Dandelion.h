#pragma once

#include <stdio.h>
#include "Plant.h"

class Dandelion : public Plant {
public:
    Dandelion(World* currentWorld, int posX, int posY, int age, bool newBorn);
    void draw() override;
    void action() override;
    string getName() override;
    Organism* clone(int posX, int posY) override;
    ~Dandelion() override;
};

