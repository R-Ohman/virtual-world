#pragma once
#ifndef _HUMAN_H_
#define _HUMAN_H_

#include <stdio.h>
#include <string>
#include <conio.h>
#include "Animal.h"
// Без этого будут ошибки в .cpp
#include "World.h"
using std::string;

class Human : public Animal {
private:
    int humanRegeneration;
public:
    Human() = default;
    Human(World* world, unsigned posX = -1, unsigned posY = -1, unsigned age = 0, unsigned regeneration = 5);
    void draw() override;
    void action() override;
    int getRegeneration();
    std::string getName() override;
    void specialAbility();
    Organism* createClone(unsigned x, unsigned y) override;
    ~Human();
};

#endif