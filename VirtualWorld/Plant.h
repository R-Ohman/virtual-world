#ifndef Plant_h
#define Plant_h

#include <stdio.h>
#include <stdlib.h>
#include "Organism.h"

class Plant : public Organism {
public:
    Plant() = default;
    Plant(World* currentWorld, int strength, int pos_x, int pos_y, int age, bool newBorn);
    void action() override;
    ~Plant();
};

#endif