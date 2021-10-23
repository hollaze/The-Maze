#include "../headers/maze.h"

/**
 * update - update delta time and player movements
 * @delta_time: frame limitations
 * @ticks_last_frame: ticks from last frame
 * @player: player struct values
 * Return: void
 */

void update(void)
{
	float delta_time;

	while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticks_last_frame + FRAME_TIME_LENGTH));

	delta_time = (SDL_GetTicks() - ticks_last_frame) / 1000.0f;

	ticks_last_frame = SDL_GetTicks();

	movePlayer(delta_time);
	castAllRays();
}

/**
 * setup_player - setup all player values
 * Return: player values
 */

void setup_player(void)
{
	player.x = WINDOW_WIDTH / 2;  /* Center in x position */
	player.y = WINDOW_HEIGHT / 2; /* Center in y position */
	player.width = 1;
	player.height = 1;
	player.turn_direction = 0;
	player.walk_direction = 0;
	player.rotation_angle = PI / 2; /* 90 degrees */
	player.walk_speed = 120;
	player.turn_speed = 60 * (PI / 180); /* degrees to radians -> 60 deg */
}

/**
 * movePlayer - handle the rotation and the player movement
 * also do not update player movements if player continue
 * towards a wall
 *
 * @delta_time: frame limitation
 * @player: player struct values
 *
 * Return: player values
 */

void movePlayer(float delta_time)
{
	float move_step;
	float new_player_x, new_player_y;

	player.rotation_angle += player.turn_direction *
				 player.turn_speed *
				 delta_time;
	move_step = player.walk_direction * player.walk_speed * delta_time;

	new_player_x = player.x + cos(player.rotation_angle) * move_step;
	new_player_y = player.y + sin(player.rotation_angle) * move_step;

	/* set new player position only if player is not colliding with walls */
	if (!mapHasWallAt(new_player_x, new_player_y))
	{
		player.x = new_player_x;
		player.y = new_player_y;
	}
}
