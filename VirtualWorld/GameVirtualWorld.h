#pragma once
#ifndef _GAMEVIRTUALWORLD_H_
#define _GAMEVIRTUALWORLD_H_
#include "World.h"

class GameVirtualWorld
{
private:
	World* world;
	void drawMenu();
	void game();
public:
	GameVirtualWorld() = default;
	void start();
	~GameVirtualWorld();
};

#endif