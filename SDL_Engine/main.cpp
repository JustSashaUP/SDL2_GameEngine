#include "Engine.h"
#include "SDL.h"

#define FPS 60;

Engine* game = nullptr;

int main(int argc, char* argv[])
{
	const int frameDelay = 1000 / FPS;

	Uint64 frameStart;
	int deltaTime;

	game = new Engine();

	game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, false);
	while (game->running())
	{
		frameStart = SDL_GetTicks64();
		game->handleEvents();
		game->update();
		game->fixedupdate();
		game->render();
		deltaTime = SDL_GetTicks64() - frameStart;

		if (frameDelay > deltaTime)
		{
			SDL_Delay(frameDelay - deltaTime);
		}
	}

	game->clean();
	return 0;
}