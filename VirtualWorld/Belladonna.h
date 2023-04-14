#pragma once
#ifndef _BELLADONNA_H_
#define _BELLADONNA_H_

#include "Plant.h"
#include "Parameters.h"

class Belladonna : public Plant {
protected:
    void draw() const override;
    string getName() const override;
    Organism* createClone(unsigned x, unsigned y) const override;
    
public:
    Belladonna() = default;
    Belladonna(World* currentWorld, unsigned posX = -1, unsigned posY = -1, unsigned age = 0, unsigned strength = BELLADONNA_STRENGTH);
    ~Belladonna() override;
};

#endif