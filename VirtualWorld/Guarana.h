#pragma once
#ifndef _GUARANA_H_
#define _GUARANA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Plant.h"

class Guarana : public Plant {
public:
    Guarana() = default;
    Guarana(World* currentWorld, unsigned posX = 0, unsigned posY = 0, unsigned age = 0);
    void draw() override;
    string getName() override;
    Organism* createClone(unsigned x, unsigned y) override;
    ~Guarana() override;
};

#endif