#pragma once
#ifndef _FOX_H_
#define _FOX_H_

#include "Animal.h"
#include "Parameters.h"

class Fox : public Animal {
protected:
    void draw() const override;
    void action() override;
    string getName() const override;
    Organism* createClone(unsigned x, unsigned y) const override;

public:
    Fox() = default;
    Fox(World* currentWorld, unsigned posX = -1, unsigned posY = -1, unsigned age = 0, unsigned strength = FOX_STRENGTH);
    ~Fox() override;
};

#endif