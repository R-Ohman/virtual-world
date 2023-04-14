#pragma once
#ifndef _GRASS_H_
#define _GRASS_H_

#include "Plant.h"
#include "Parameters.h"

class Grass : public Plant {
protected:
    void draw() const override;
    string getName() const override;
    Organism* createClone(unsigned x, unsigned y) const override;

public:
    Grass() = default;
    Grass(World* currentWorld, unsigned posX = -1, unsigned posY = -1, unsigned age = 0, unsigned strength = GRASS_STRENGTH);
    ~Grass() override;
};

#endif