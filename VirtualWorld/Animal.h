﻿#pragma once
#ifndef _ANIMAL_H_
#define _ANIMAL_H_

class Organism;
#include <iostream>
#include <string>
#include "Organism.h"

using std::string;

// Zwierzęta dziedziczą po klasie Organizm
class Animal : public Organism {
public:
    Animal() = default;
    Animal(World* world, unsigned strength, unsigned initiative, unsigned posX = -1, unsigned posY = -1, unsigned age = 0);
    bool sameSpecies(Organism& entity);
    void breed();
    std::string getName() override = 0;         // Każde zwierzę ma inną nazwę
    void draw() override = 0;                   // Każde zwierzę jest inaczej oznaczane
    void action() override;                     // Każde zwierzę inaczej się zachowuje
	void collision(Organism* collidingEntity) override;
   // virtual void collision(Organism* collidingEntity);
    ~Animal();
};

#endif