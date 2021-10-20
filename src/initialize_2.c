#include "../headers/maze.h"
#include <stdlib.h>

/**
 * setup - setup all player values
 * Return: player values
 */

player_struct setup_player(void)
{
	player_struct player;

	player.x = WINDOW_WIDTH / 2; 	/* Center in x position */
	player.y = WINDOW_HEIGHT / 2;	/* Center in y position */
	player.width = 5;
	player.height = 5;
	player.turn_direction = 0;
	player.walk_direction = 0;
	player.rotation_angle = PI / 2;	/* 90 degrees */
	player.walk_speed = 2;
	player.turn_speed = 60 * (PI / 180); /* 45 degrees per second */

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

	player_rect.x = player.x;
	player_rect.y = player.y;
	player_rect.w = player.width;
	player_rect.h = player.height;

	if (SDL_RenderFillRect(renderer, &player_rect) != 0)
		exitWithError("renderPlayer, cannot fill rectangle");

	if (SDL_RenderDrawLine(renderer,
			       player.x,
			       player.y,
			       (player.x + cos(player.rotation_angle) * 40)
			      ,
			       (player.y + sin(player.rotation_angle) * 40)
			      ) != 0)
		exitWithError("renderPlayer, cannot render draw line");
}
