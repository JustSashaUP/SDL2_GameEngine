#ifndef MAP_H
#define MAP_H

#include "Engine.h"

class Map
{
public:
	Map(const char* fileName);
	~Map();

	void LoadMap(const char* fileName);
	void DrawMap();
private:
	SDL_Rect src, dest;

	SDL_Texture* texture;
};

#endif