#pragma once
#ifndef _ORGANISM_H_
#define _ORGANISM_H_

#include <iostream>
#include <string>
class World;
using std::string;

class Organism {
protected:
	// Pointer to the world in which the organism is located
    World* world;
    unsigned strength, initiative, age;
	// position[0] - x, position[1] - y
    unsigned position[2];

	// Constructor for child class objects
    Organism(World* world, unsigned strength, unsigned initiative, unsigned posX = -1, unsigned posY = -1, unsigned age = 0);
    
    virtual Organism* createClone(unsigned x, unsigned y) const = 0;
    virtual void collision(Organism* collidingEntity) {}
    
public:
	Organism() = default;
    
    virtual unsigned* getNeighboringPosition() const;
    unsigned* getUnoccupiedNeighboringPosition() const;

    unsigned getStrength() const;
    unsigned getInitiative() const;
    unsigned getX() const;
    unsigned getY() const;
    unsigned getAge() const;

    void setX(unsigned x);
    void setY(unsigned y);
    void setAge(unsigned age);

    virtual void action() = 0;
    virtual std::string getName() const = 0;
    virtual void draw() const = 0;
    virtual bool repulsedAttack(Organism* entity) const;
    
    virtual ~Organism();
};

#endif