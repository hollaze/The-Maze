#include "../headers/maze.h"

float horizontalStepX(float ray_angle)
{
	float step_x;

	step_x = TILE_SIZE / tan(ray_angle);
	step_x *= (isRayFacingLeft(ray_angle) && step_x > 0) ? -1 : 1;
	step_x *= (isRayFacingRight(ray_angle) && step_x < 0) ? -1 : 1;

	return (step_x);
}

float horizontalStepY(float ray_angle)
{
	float step_y;

	step_y = TILE_SIZE;
	step_y *= isRayFacingUp(ray_angle) ? -1 : 1;

	return (step_y);
}

float verticalStepX(float ray_angle)
{
	float step_x;

	step_x = TILE_SIZE;
	step_x *= isRayFacingLeft(ray_angle) ? -1 : 1;

	return (step_x);
}

float verticalStepY(float ray_angle)
{
	float step_y;

	step_y = TILE_SIZE * tan(ray_angle);
	step_y *= (isRayFacingUp(ray_angle) && step_y > 0) ? -1 : 1;
	step_y *= (isRayFacingDown(ray_angle) && step_y < 0) ? -1 : 1;

	return (step_y);
}
