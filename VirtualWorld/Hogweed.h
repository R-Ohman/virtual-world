#pragma once
#ifndef _HOGWEED_H_
#define _HOGWEED_H_

#include "Plant.h"
#include "Parameters.h"

class Hogweed : public Plant {
protected:
    void draw() const override;
    string getName() const override;
    Organism* createClone(unsigned x, unsigned y) const override;
    void action() override;
    
public:
    Hogweed() = default;
    Hogweed(World* currentWorld, unsigned posX = -1, unsigned posY = -1, unsigned age = 0, unsigned strength = HOGWEED_STRENGTH);
    ~Hogweed() override;
};

#endif