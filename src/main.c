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
	SDL_Color orange = {255, 127, 40, 255};
	SDL_Rect rect = {300, 100, 200, 100};

	/* Cannot Initialize SDL video */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("ERREUR : Initialisation SDL > %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/* width, height, window flag, window, renderer */
	if (SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer) != 0)
		exit_with_error("Cannot create window and renderer");
	SDL_SetWindowTitle(window, "The Maze");

	/* Red, Green, Blue, Alpha */
	if (SDL_SetRenderDrawColor(renderer, orange.r, orange.g, orange.b, orange.a) != 0)
		exit_with_error("Cannot Set Color");

	/* renderer, x, y */
	if (SDL_RenderDrawPoint(renderer, 100, 450) != 0)
		exit_with_error("Cannot draw point");

	if (SDL_RenderDrawLine(renderer, 50, 50, 500, 500) != 0)
		exit_with_error("Cannot draw line");

	if (SDL_RenderDrawRect(renderer, &rect) != 0)
		exit_with_error("Cannot drawn rectangle");
	
	if (SDL_RenderFillRect(renderer, &rect) != 0)
		exit_with_error("Cannot fill the rectangle with color");

	/* Set color for all window
	if (SDL_RenderClear(renderer) != 0)
		exit_with_error("Cannot clear renderer");
	*/

	/* Load renderer */
	SDL_RenderPresent(renderer);
	/* Window delay */
	SDL_Delay(5000);
	/* Free renderer */
	SDL_DestroyRenderer(renderer);
	/* Free window */
	SDL_DestroyWindow(window);

	SDL_Quit();

	return (EXIT_SUCCESS);
}
