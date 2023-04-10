#pragma once
#ifndef _ANTELOPE_H_
#define _ANTELOPE_H_

#include "Animal.h"

class Antelope : public Animal {
protected:
    void draw() const override;
    string getName() const override;
    Organism* createClone(unsigned x, unsigned y) const override;
    
    void collision(Organism* collidingEntity) override;
    unsigned* getNeighboringPosition() const override;
    
public:
    Antelope() = default;
    Antelope(World* currentWorld, unsigned posX = -1, unsigned posY = -1, unsigned age = 0);
    ~Antelope() override;
};

#endif