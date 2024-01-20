#ifndef ENGINE_H
#define ENGINE_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#include <iostream>
#include <vector>


class Engine
{
public:
	Engine();
	~Engine();

	static SDL_Renderer* renderer;
	static SDL_Event event;

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void update();
	void fixedupdate();
	void render();
	void clean();

	void handleEvents();

	bool running() { return isRunning; }

private:

	SDL_Window* window;

	int counter = 0;
	bool isRunning;
};
#endif

