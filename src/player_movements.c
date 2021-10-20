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
 * @ticks_last_frame: ticks of the last frame
 * Return: ticks_last_frame
 */

int ticksLastFrame(int ticks_last_frame)
{
	ticks_last_frame = SDL_GetTicks();
	return (ticks_last_frame);
}

/**
 * update - update delta time and player movements
 * @delta_time: delta time
 * @ticks_last_frame: ticks from last frame
 * Return: void
 */

player_struct update(float delta_time, int ticks_last_frame, player_struct player)
{
	int time_to_wait;

	time_to_wait = FRAME_TIME_LENGTH - (SDL_GetTicks() - ticks_last_frame);

	if (time_to_wait > 0 && time_to_wait <= FRAME_TIME_LENGTH)
		SDL_Delay(time_to_wait);

	delta_time = deltaTime(delta_time, ticks_last_frame);
	ticks_last_frame = ticksLastFrame(ticks_last_frame);

	player = movePlayer(delta_time, player);

	return (player);

	/* TODO: remember to update game objects as a function of deltatime */
}

player_struct movePlayer(float delta_time, player_struct player)
{
	float move_step;

	player.rotation_angle += player.turn_direction * player.turn_speed * delta_time;
	move_step = player.walk_direction * player.walk_speed;

	player.x += cos(player.rotation_angle) * move_step;
	player.y += sin(player.rotation_angle) * move_step;

	return (player);
}
