#ifndef Sheep_h
#define Sheep_h

#include <stdio.h>
#include "Animal.h"

class Sheep : public Animal {
public:
    Sheep() = default;
    Sheep(World* currentWorld, int posX, int posY, int age, bool newBorn);
    void draw() override;
    string getName() override;
    Organism* createClone(unsigned x, unsigned y) override;
    ~Sheep() override;
};

#endif