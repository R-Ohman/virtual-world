#pragma once
#ifndef _WORLD_H_
#define _WORLD_H_

#include "Parameters.h"

using std::string;


struct Node {
    Organism* entity;
    Node* next;
};

// Linked list of entities sorted by initiative (and then by age)
class Entities {
private:
    unsigned allocatedSize;
    unsigned size = 0;
public:
    Entities(unsigned allocatedSize);
    Node* head;
    
    unsigned getAllocSize() const;
    unsigned getSize() const;
    
    void setSize(unsigned size);
    void add(Organism* entity);
    void remove(Organism* entity);
    
    ~Entities();
};


class World {
private:
    unsigned width, height;
    unsigned turnNumber;

    void drawHeader() const;
    
public:
    World() = default;
    World(unsigned w, unsigned h);
	// Constructor for loading world from file with saved state
    World(std::ifstream& loadFile);
    
    // 2D array of pointers to entities
    Organism*** entitiesField;
    // List of entities sorted by initiative (and then by age)
    Entities* entitiesList;
    
    unsigned getWidth() const;
    unsigned getHeight() const;
    unsigned getTurnNumber() const;
    
    void placeRandom(Organism* entity);
    bool gameContinues() const;
    
    void drawWorld() const;
    void makeTurn();
    void saveWorld();

    ~World();
};

#endif