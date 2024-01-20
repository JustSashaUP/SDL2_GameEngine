#include "Engine.h"

SDL_Renderer* Engine::renderer = nullptr;
SDL_Event Engine::event;

Engine::Engine() {}

Engine::~Engine() {}

void Engine::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Game Subsystem is initialised!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window is created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			std::cout << "Renderer is created!" << std::endl;
		}
		isRunning = true;
	}
}

void Engine::fixedupdate()
{
	
}

void Engine::update()
{
	std::cout << "FrameTime: "<< counter++ << std::endl;
}

void Engine::render()
{
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

void Engine::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Engine::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}