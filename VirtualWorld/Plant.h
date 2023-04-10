#pragma once
#ifndef _PLANT_H_
#define _PLANT_H_

#include "Organism.h"

class Plant : public Organism {
protected:
    Plant(World* currentWorld, unsigned strength, unsigned initiative = 0, unsigned posX = -1, unsigned posY = -1, unsigned age = 0);
    void action() override;
    
public:
    Plant() = default;
    ~Plant();
};

#endif