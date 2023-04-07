#ifndef Fox_h
#define Fox_h

#include <stdio.h>
#include "Animal.h"

class Fox : public Animal {
public:
    Fox() = default;
    Fox(World* currentWorld, int posX, int posY, int age, bool newBorn);
    void draw() override;
    string getName() override;
    void action() override;
    Organism* createClone(unsigned x, unsigned y) override;
    ~Fox() override;
};

#endif