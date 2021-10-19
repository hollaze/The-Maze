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

double deltaTime(double delta_time, int ticks_last_frame)
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

void update(double delta_time, int ticks_last_frame)
{
	int time_to_wait;

	time_to_wait = FRAME_TIME_LENGTH - (SDL_GetTicks() - ticks_last_frame);

	if (time_to_wait > 0 && time_to_wait <= FRAME_TIME_LENGTH)
		SDL_Delay(time_to_wait);

	delta_time = deltaTime(delta_time, ticks_last_frame);
	ticks_last_frame = ticksLastFrame(ticks_last_frame);

	/*movePlayer(delta_time);*/

	/* TODO: remember to update game objects as a function of deltatime */
}

/*void movePlayer(double delta_time)
{

}*/
