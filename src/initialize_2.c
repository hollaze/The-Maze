#include "../headers/maze.h"
#include <stdlib.h>

/**
 * setup - setup all player values
 * Return: player values
 */

player_struct setup(void)
{
	player_struct player;

	player.x = WINDOW_WIDTH / 2;
	player.y = WINDOW_HEIGHT / 2;
	player.width = 5;
	player.height = 5;
	player.turn_direction = 0;
	player.walk_direction = 0;
	player.rotation_angle = PI / 2; /* 90 degrees */
	player.walk_speed = 100;
	player.turn_speed = 45 * (PI / 180); /* 45 degrees per second */

	return (player);
}

/**
 * renderPlayer - render player on screen
 * @renderer: renderer value to render player
 * @player: player struct values
 * Return: void
 */

void renderPlayer(SDL_Renderer *renderer, player_struct player)
{
	SDL_Rect player_rect;

	if (SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255) != 0)
		exitWithError("renderPlayer, cannot set render draw color");

	player_rect.x = player.x * MINIMAP_SCALE_FACTOR;
	player_rect.y = player.y * MINIMAP_SCALE_FACTOR;
	player_rect.w = player.width * MINIMAP_SCALE_FACTOR;
	player_rect.h = player.height * MINIMAP_SCALE_FACTOR;

	if (SDL_RenderFillRect(renderer, &player_rect) != 0)
		exitWithError("renderPlayer, cannot fill rectangle");

	if (SDL_RenderDrawLine(renderer,
			       player.x * MINIMAP_SCALE_FACTOR,
			       player.y * MINIMAP_SCALE_FACTOR,
			       (player.x + cos(player.rotation_angle) * 40)
			       * MINIMAP_SCALE_FACTOR,
			       (player.y + sin(player.rotation_angle) * 40)
			       * MINIMAP_SCALE_FACTOR) != 0)
		exitWithError("renderPlayer, cannot render draw line");
}
