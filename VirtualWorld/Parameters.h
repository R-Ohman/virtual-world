#pragma once
#ifndef _PARAMETERS_H_
#define _PARAMETERS_H_

#define HUMAN_STRENGTH		5
#define WOLF_STRENGTH		9
#define SHEEP_STRENGTH		4
#define FOX_STRENGTH		3
#define TURTLE_STRENGTH		2
#define ANTELOPE_STRENGTH	4
#define GRASS_STRENGTH		0
#define DANDELION_STRENGTH	0
#define GUARANA_STRENGTH	0
#define BELLADONNA_STRENGTH	99
#define HOGWEED_STRENGTH	10

#define HUMAN_INITIATIVE		4
#define WOLF_INITIATIVE			5
#define SHEEP_INITIATIVE		4
#define FOX_INITIATIVE			7
#define TURTLE_INITIATIVE		1
#define ANTELOPE_INITIATIVE		4
#define GRASS_INITIATIVE		0
#define DANDELION_INITIATIVE	0
#define GUARANA_INITIATIVE		0
#define BELLADONNA_INITIATIVE	0
#define HOGWEED_INITIATIVE		0

#define REGENERATION_TIME	5
#define SUPERPOWER_TIME		5
#define LEFT_ARROW			75
#define RIGHT_ARROW			77
#define UP_ARROW			72
#define DOWN_ARROW			80

#define WORLD_SIZE_FOR_ORGANISMS_GROUP	80
#define ORGANISMS_NUMBER				10
#define ACTIVATE_SUPERPOWER_BUTTON		'r'
#define SAVE_WORLD_BUTTON				's'
#define EXIT_GAME_BUTTON				'q'

#include "Organism.h"

#include "Animal.h"
#include "Human.h"
#include "Sheep.h"
#include "Wolf.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"

#include "Plant.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "Hogweed.h"

#include <iostream>
#include <fstream>
#include <time.h>

#endif