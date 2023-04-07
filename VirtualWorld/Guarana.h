#ifndef Guarana_h
#define Guarana_h

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Plant.h"

class Guarana : public Plant {
public:
    Guarana() = default;
    Guarana(World* currentWorld, int posX, int posY, int age, bool newBorn);
    void draw() override;
    string getName() override;
    Organism* clone(int posX, int posY) override;
    ~Guarana() override;
};

#endif