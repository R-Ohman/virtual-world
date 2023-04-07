#ifndef Hogweed_h
#define Hogweed_h

#include <stdio.h>
#include "Plant.h"

class Hogweed : public Plant {
public:
    Hogweed() = default;
    Hogweed(World* currentWorld, int posX, int posY, int age, bool newBorn);
    void draw() override;
    void action() override;
    string getName() override;
    Organism* createClone(unsigned x, unsigned y) override;
    ~Hogweed() override;
};

#endif