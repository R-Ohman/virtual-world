#ifndef Human_h
#define Human_h

#include <stdio.h>
#include <string>
#include <conio.h>
#include "Animal.h"
// WARN
#include "World.h"
using std::string;

class Human : public Animal {
public:
    Human() = default;
    Human(World* world, unsigned posX, unsigned posY, unsigned age);
    void draw() override;
    void action() override;
    std::string getName() override;
    void specialAbility();
    Organism* createClone(unsigned x, unsigned y) override;
    ~Human();
};

#endif