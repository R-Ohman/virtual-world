#pragma once
#ifndef _DANDELION_H_
#define _DANDELION_H_

#include "Plant.h"

class Dandelion : public Plant {
protected:
    void draw() const override;
    void action() override;
    string getName() const override;
    Organism* createClone(unsigned x, unsigned y) const override;
    
public:
    Dandelion() = default;
    Dandelion(World* currentWorld, unsigned posX = -1, unsigned posY = -1, unsigned age = 0);
    ~Dandelion() override;
};

#endif