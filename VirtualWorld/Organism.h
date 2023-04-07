#ifndef Organism_h
#define Organism_h

class World;
#include <iostream>
#include <string>
using std::string;

class Organism {
protected:
    World* world;                         // Świat w którym się znajduje organizm
    unsigned strength;                           // Siła organizmu
    unsigned initiative;                         // Inicjatywa organizmu
    unsigned position[2];                        // Pozycja X oraz Y
    unsigned age;                                // Wiek organizmu, ustalany z góry w konstruktorze
public:
	Organism() = default;
	Organism(World* world, unsigned strength, unsigned initiative, unsigned posX, unsigned posY, unsigned age = 0);
    virtual int* pathFindNewField();        // Znalezienie miejsca do poruszenia się
    int* pathFindNewUnoccupiedField();      // Znalezienie niezajętego miejsca do poruszenia się

    unsigned getStrength();
    unsigned getInitiative();
    void setX(unsigned x);
    void setY(unsigned y);
    unsigned getX();
    unsigned getY();
    unsigned getAge();

    virtual bool repulsedAttack(Organism* entity);               // Organizm żółw może odbijać ataki kierowane w jego stronę
    virtual Organism* createClone(unsigned x, unsigned y) = 0;   // Rozmnażanie się organizmów

    virtual std::string getName() = 0;
    // rysowanie() → powoduje narysowanie symbolicznej reprezentacji organizmu
    virtual void draw() = 0;
    // akcja() → określa zac howanie organizmu w trakcie tury
    virtual void action() = 0;
    // kolizja() → określa zachowanie organizmu w trakcie kontaktu/zderzenia z innym organizmem
    virtual void collision(Organism* collidingEntity) {}
    
    virtual ~Organism();
};

#endif