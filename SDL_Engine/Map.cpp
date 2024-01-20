#include "Map.h"
#include "Engine.h"
#include "TextureManager.h"

Map::Map(const char* fileName)
{

	Engine* game;

	Map::LoadMap(fileName);

	src.x = src.y = 0;
	src.w = dest.w = 1600;
	src.h = dest.h = 800;

	dest.x = dest.y = 0;
}

Map::~Map()
{
	SDL_DestroyTexture(texture);
}


void Map::LoadMap(const char* fileName)
{
	texture = TextureManager::LoadTexture(fileName);
}

void Map::DrawMap()
{
	TextureManager::Draw(texture, src, dest);
}