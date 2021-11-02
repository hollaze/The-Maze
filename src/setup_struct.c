#include "../headers/maze.h"
#include <stdlib.h>

/**
 * setupRendering - setup rendering struct values
 *
 * Return: void
 */

void setupRendering(void)
{
	r.color_buffer = NULL;
	r.window = NULL;
	r.renderer = NULL;
	r.color_buffer_texture = NULL;
}

/**
 * setupPlayer - setup all player values
 *
 * Return: void
 */

void setupPlayer(void)
{
	player.x = WINDOW_WIDTH / 2;  /* Center in x position */
	player.y = WINDOW_HEIGHT / 2; /* Center in y position */
	player.width = 1;
	player.height = 1;
	player.turn_direction = 0;
	player.walk_direction = 0;
	player.rotation_angle = -(PI / 2); /* 90 degrees up */
	player.walk_speed = 120;
	player.turn_speed = 60 * (PI / 180); /* degrees to radians -> 60 deg */
	player.is_game_running = FALSE;
}

/**
 * setupCollDetect - seting up the coll_detect struct values
 *
 * Return: void
 */

void setupCollDetect(void)
{
	/* horizontal */
	cd.found_horizontal_wall_hit = FALSE;
	cd.horizontal_wall_hit_x = 0;
	cd.horizontal_wall_hit_y = 0;
	cd.horizontal_wall_content = 0;
	/* vertical */
	cd.found_vertical_wall_hit = FALSE;
	cd.vertical_wall_hit_x = 0;
	cd.vertical_wall_hit_y = 0;
	cd.vertical_wall_content = 0;
}
