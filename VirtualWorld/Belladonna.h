#pragma once

#include <stdio.h>
#include "Plant.h"
#include <string>

class Belladonna : public Plant {
public:
    Belladonna(World* currentWorld, int posX, int posY, int age, bool newBorn);
    void draw() override;
    string getName() override;
    Organism* clone(int posX, int posY) override;
    ~Belladonna() override;
};

