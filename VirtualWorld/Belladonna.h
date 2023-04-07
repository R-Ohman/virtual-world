#ifndef Belladonna_h
#define Belladonna_h

#include <stdio.h>
#include "Plant.h"
#include <string>

class Belladonna : public Plant {
public:
    Belladonna() = default;
    Belladonna(World* currentWorld, int posX, int posY, int age, bool newBorn);
    void draw() override;
    string getName() override;
    Organism* createClone(unsigned x, unsigned y) override;
    ~Belladonna() override;
};

#endif