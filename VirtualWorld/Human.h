#ifndef Human_h
#define Human_h
#include <stdio.h>
#include <string>
#include "Animal.h"

using std::string;

class Human : public Animal {
public:
    Human() = default;
    Human(World* currentWorld, int posX, int posY, int age);
    void draw() override;
    void action() override;
    std::string getName() override;
    void specialAbility();
    Organism* clone(int posX, int posY) override;
    ~Human();
};

#endif