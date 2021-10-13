#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>

void exit_with_error(const char *message)
{
	SDL_Log("Error: %s > %s", message, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}

int main(void)
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	/* Cannot Initialize SDL video */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("ERREUR : Initialisation SDL > %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/* width, height, window flag, window, renderer */
	if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_MINIMIZED, &window, &renderer) != 0)
		exit_with_error("Cannot create window and renderer");
	SDL_SetWindowTitle(window, "The Maze");


	/* Window delay */
	SDL_Delay(5000);
	/* Free window */
	SDL_DestroyWindow(window);
	/* Free renderer */
	SDL_DestroyRenderer(renderer);

	SDL_Quit();

	return (EXIT_SUCCESS);
}
