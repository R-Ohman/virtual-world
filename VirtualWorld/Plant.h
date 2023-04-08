#pragma once
#ifndef _PLANT_H_
#define _PLANT_H_

#include <stdio.h>
#include <stdlib.h>
#include "Organism.h"

class Plant : public Organism {
public:
    Plant() = default;
    Plant(World* currentWorld, unsigned strength, unsigned posX = 0, unsigned posY = 0, unsigned age = 0);
    void action() override;
    ~Plant();
};

#endif