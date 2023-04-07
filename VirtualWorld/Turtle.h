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
    bool reflected(Organism* entity) override;
    Organism* clone(int posX, int posY) override;
    ~Turtle() override;
};

#endif