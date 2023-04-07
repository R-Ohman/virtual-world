#pragma once

#include <stdio.h>
#include "Plant.h"

class Hogweed : public Plant {
public:
    Hogweed(World* currentWorld, int posX, int posY, int age, bool newBorn);
    void draw() override;
    void action() override;
    string getName() override;
    Organism* clone(int posX, int posY) override;
    ~Hogweed() override;
};
