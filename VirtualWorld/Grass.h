#ifndef Grass_h
#define Grass_h

#include <stdio.h>
#include "Plant.h"

class Grass : public Plant {
public:
    Grass() = default;
    Grass(World* currentWorld, int posX, int posY, int age, bool newBorn);
    void draw() override;
    string getName() override;
    Organism* createClone(unsigned x, unsigned y) override;
    ~Grass() override;
};

#endif