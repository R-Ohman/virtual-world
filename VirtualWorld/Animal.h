#pragma once
#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include "Organism.h"
using std::string;

// Zwierzęta dziedziczą po klasie Organizm
class Animal : public Organism {
protected:
    Animal(World* world, unsigned strength, unsigned initiative, unsigned posX = -1, unsigned posY = -1, unsigned age = 0);
    
    bool sameSpecies(const Organism& entity) const;
    std::string getName() const override = 0;
    void draw() const override = 0;
    
    void breed() const;
    void action() override;
    void collision(Organism* collidingEntity) override;
    
public:
    Animal() = default;
    ~Animal();
};

#endif