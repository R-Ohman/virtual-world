#pragma once

#include <stdio.h>
#include "Animal.h"

class Human : public Animal {
public:
    Human(World* currentWorld, int posX, int posY, int age);
    void draw() override;
    void action() override;
    string getName() override;
    void specialAbility();
    Organism* clone(int posX, int posY) override;
    ~Human();
};

