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
    Organism* clone(int posX, int posY) override;
    ~Hogweed() override;
};

#endif