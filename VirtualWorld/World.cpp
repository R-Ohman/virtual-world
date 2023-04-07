#include "World.h"

Entities::Entities(int maxSize)
{
}

int Entities::getMaxSize()
{
    return 0;
}

int Entities::getCurrentSize()
{
    return 0;
}

void Entities::add(Organism* entity)
{
}

void Entities::remove(Organism* entity)
{
}

Entities::~Entities()
{
}

World::World(int N, int M)
{
}

World::World(int N, int M, std::ifstream& loadFile)
{
}

int World::getN()
{
    return 0;
}

int World::getM()
{
    return 0;
}

int World::getHumanCooldown()
{
    return 0;
}

int World::getTurn()
{
    return 0;
}

bool World::getGameStatus()
{
    return false;
}

void World::setGameStatus()
{
}

void World::setHumanCooldown(int i)
{
}

void World::setTurn(int turn)
{
}

void World::drawWorld()
{
}

void World::makeTurn()
{
}

void World::placeRandom(Organism* entity)
{
}

void World::placeSpecific(Organism* entity, int axisN, int axisM)
{
}

void World::saveWorld()
{
}

World World::loadWorld()
{
    return World();
}
