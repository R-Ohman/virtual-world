#pragma once
#ifndef _HUMAN_H_
#define _HUMAN_H_

#include <conio.h>
#include "Animal.h"
#include "World.h"
using std::string;

class Human : public Animal {
private:
    int humanRegeneration; // 1-5 - regeneration, 6-10 superpower is activated
    
protected:
    void draw() const override;
    void action() override;
    void specialAbility();

    std::string getName() const override;
    Organism* createClone(unsigned x, unsigned y) const override;
    
public:
    Human() = default;
    Human(World* world, unsigned posX = -1, unsigned posY = -1, unsigned age = 0, unsigned regeneration = 5, unsigned strength = HUMAN_STRENGTH);
    ~Human();
    
    void setStrength(unsigned strength);
    int getRegeneration();
};

#endif