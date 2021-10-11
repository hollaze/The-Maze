#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	SDL_Window *window = NULL;

	/* Cannot Initialize SDL video */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("ERREUR : Initialisation SDL > %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/* Title, x, y, width, height, flags -> window type */
	window = SDL_CreateWindow("Première fenêtre SDL 2",
				  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				  800, 600, SDL_WINDOW_MINIMIZED);

	if (window == NULL)
	{
		SDL_Log("ERREUR : Creation fenêtre échouée > %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/* Window delay */
	SDL_Delay(5000);

	SDL_Quit();

	return (EXIT_SUCCESS);
}
