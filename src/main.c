#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

int main(void)
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	get_wrt wrt;
	is_game_running game_running;
	player_struct player = {PLAYER_X, PLAYER_Y}; /* setup player spawn */

	game_running.running = FALSE;

	game_running.running = initializeWindowAndRenderer(window, renderer);
	get_W(&wrt, window);
	get_R(&wrt, renderer);

	while (game_running.running)
	{
		game_running.running = processQuitAndEscape(game_running, game_running.running);
		update(player);
		render(wrt.renderer, player);
		get_R(&wrt, renderer);
	}

	destroyAndQuit(wrt.window, wrt.renderer);

	return (0);
}
