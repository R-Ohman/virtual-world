#pragma once
#ifndef _SHEEP_H_
#define _SHEEP_H_

#include "Animal.h"

class Sheep : public Animal {
protected:
    void draw() const override;
    string getName() const override;
    Organism* createClone(unsigned x, unsigned y) const override;
    
public:
    Sheep() = default;
    Sheep(World* currentWorld, unsigned posX = -1, unsigned posY = -1, unsigned age = 0);
    ~Sheep() override;
};

#endif