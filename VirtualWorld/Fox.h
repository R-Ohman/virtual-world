#pragma once

#include <stdio.h>
#include "Animal.h"

class Fox : public Animal {
public:
    Fox(World* currentWorld, int posX, int posY, int age, bool newBorn);
    void draw() override;
    string getName() override;
    void action() override;
    Organism* clone(int posX, int posY) override;
    ~Fox() override;
};