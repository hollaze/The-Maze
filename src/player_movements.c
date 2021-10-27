#include "../headers/maze.h"

/**
 * deltaTime - time spent between actual and last frame,
 * really important for that everyone can have the same
 * speed of the game
 *
 * @delta_time: delta_time value
 * @ticks_last_frame: ticks last frame
 *
 * Return: delta_time
 */

float deltaTime(float delta_time, int ticks_last_frame)
{
	delta_time = ((SDL_GetTicks() - ticks_last_frame) / 1000.0f);
	return (delta_time);
}

/**
 * ticksLastFrame - ticks of the last frame,
 * important for delta time
 *
 * @ticks_last_frame: ticks of the last frame
 *
 * Return: ticks_last_frame
 */

int ticksLastFrame(int ticks_last_frame)
{
	ticks_last_frame = SDL_GetTicks();
	return (ticks_last_frame);
}

/**
 * update - update delta time, player movements and raycasting
 * @delta_time: frame limitations
 * @ticks_last_frame: ticks from last frame
 * Return: void
 */

void update(float delta_time, int ticks_last_frame)
{
	int time_to_wait;

	time_to_wait = FRAME_TIME_LENGTH - (SDL_GetTicks() - ticks_last_frame);

	if (time_to_wait > 0 && time_to_wait <= FRAME_TIME_LENGTH)
		SDL_Delay(time_to_wait);

	delta_time = deltaTime(delta_time, ticks_last_frame);
	ticks_last_frame = ticksLastFrame(ticks_last_frame);

	movePlayer(delta_time);
	castAllRays();
}

/**
 * movePlayer - handle the rotation and the player movement
 * also do not update player movements if player continue
 * towards a wall
 *
 * @delta_time: frame limitation
 *
 * Return: player values
 */

void movePlayer(float delta_time)
{
	float move_step;
	float new_player_x, new_player_y;

	/* from the rotation angle, handle the next angle rotations */
	player.rotation_angle += player.turn_direction *
				 player.turn_speed *
				 delta_time;
	/* check if movement is forward or backward and add speed to it */
	move_step = player.walk_direction * player.walk_speed * delta_time;

	/* movement in x position */
	new_player_x = player.x + cos(player.rotation_angle) * move_step;
	/* movement in y position */
	new_player_y = player.y + sin(player.rotation_angle) * move_step;

	/* set new player position only if player is not colliding with walls */
	if (mapHasWallAt(new_player_x, new_player_y) == 0)
	{
		player.x = new_player_x;
		player.y = new_player_y;
	}
}
