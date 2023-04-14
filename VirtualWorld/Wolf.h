#pragma once
#ifndef _WOLF_H_
#define _WOLF_H_

#include <stdio.h>
#include "Animal.h"
#include "Parameters.h"

class Wolf : public Animal {
protected:
    void draw() const override;
    string getName() const override;
    Organism* createClone(unsigned x, unsigned y) const override;
    
public:
    Wolf() = default;
    Wolf(World* currentWorld, unsigned posX = -1, unsigned posY = -1, unsigned age = 0, unsigned strength = WOLF_STRENGTH);
    ~Wolf() override;
};

#endif