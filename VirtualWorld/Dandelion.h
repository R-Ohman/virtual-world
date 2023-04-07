#ifndef Dandelion_h
#define Dandelion_h

#include <stdio.h>
#include "Plant.h"

class Dandelion : public Plant {
public:
    Dandelion() = default;
    Dandelion(World* currentWorld, int posX, int posY, int age, bool newBorn);
    void draw() override;
    void action() override;
    string getName() override;
    Organism* createClone(unsigned x, unsigned y) override;
    ~Dandelion() override;
};

#endif