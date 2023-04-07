#ifndef Turtle_h
#define Turtle_h

#include <stdio.h>
#include "Animal.h"

class Turtle : public Animal {
public:
    Turtle() = default;
    Turtle(World* currentWorld, int posX, int posY, int age, bool newBorn);
    void draw() override;
    void action() override;
    string getName() override;
    bool repulsedAttack(Organism* entity) override;
    Organism* createClone(unsigned x, unsigned y) override;
    ~Turtle() override;
};

#endif