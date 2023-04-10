#pragma once
#ifndef _TURTLE_H_
#define _TURTLE_H_

#include "Animal.h"

class Turtle : public Animal {
protected:
    void draw() const override;
    void action() override;
    bool repulsedAttack(Organism* entity) const override;
    string getName() const override;
    Organism* createClone(unsigned x, unsigned y) const override;
    
public:
    Turtle() = default;
    Turtle(World* currentWorld, unsigned posX = -1, unsigned posY = -1, unsigned age = 0);    
    ~Turtle() override;
};

#endif