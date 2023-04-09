#pragma once
#ifndef _FOX_H_
#define _FOX_H_

#include <stdio.h>
#include "Animal.h"

class Fox : public Animal {
public:
    Fox() = default;
    Fox(World* currentWorld, unsigned posX = -1, unsigned posY = -1, unsigned age = 0);
    void draw() override;
	void action() override;
    string getName() override;
    Organism* createClone(unsigned x, unsigned y) override;
    ~Fox() override;
};

#endif