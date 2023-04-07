#ifndef Wolf_h
#define Wolf_h

#include <stdio.h>
#include "Animal.h"

class Wolf : public Animal {
public:
    Wolf() = default;
    Wolf(World* currentWorld, int posX, int posY, int age, bool newBorn);
    void draw() override;
    string getName() override;
    Organism* createClone(unsigned x, unsigned y) override;
    ~Wolf() override;
};

#endif