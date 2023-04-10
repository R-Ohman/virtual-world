#pragma once
#ifndef _GUARANA_H_
#define _GUARANA_H_

#include "Plant.h"

class Guarana : public Plant {
protected:
    void draw() const override;
    string getName() const override;
    Organism* createClone(unsigned x, unsigned y) const override;
    
public:
    Guarana() = default;
    Guarana(World* currentWorld, unsigned posX = -1, unsigned posY = -1, unsigned age = 0);
    ~Guarana() override;
};

#endif