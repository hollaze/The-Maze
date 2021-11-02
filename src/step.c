#include "../headers/maze.h"

/**
 * horizontalStepX - for each intersection of the ray on horizontal tiles,
 * get the adjacent side size of the rectangle triangle
 * also named delta x
 *
 * @ray_angle: the angle of the ray in which
 * we are measuring the points distance
 *
 * Return: distance between x points of the ray
 * touching horizontal side of the tiles
 */

float horizontalStepX(float ray_angle)
{
	float step_x;

	/* opposite size of the triangle */
	step_x = TILE_SIZE / tan(ray_angle);
	step_x *= (isRayFacingLeft(ray_angle) && step_x > 0) ? -1 : 1;
	step_x *= (isRayFacingRight(ray_angle) && step_x < 0) ? -1 : 1;

	return (step_x);
}

/**
 * horizontalStepY - for each intersection of the ray on horizontal tiles,
 * get the opposite side size of the rectangle triangle
 * also named delta y
 *
 * @ray_angle: the angle of the ray in which
 * we are measuring the points distance
 *
 * Return: distance between y points of the ray
 * touching horizontal side of the tiles
 */

float horizontalStepY(float ray_angle)
{
	float step_y;

	/* adjacent size of the triangle */
	step_y = TILE_SIZE;
	step_y *= isRayFacingUp(ray_angle) ? -1 : 1;

	return (step_y);
}

/**
 * verticalStepX - for each intersection of the ray on vertical tiles,
 * get the adjacent side size of the rectangle triangle
 * also named delta x
 *
 * @ray_angle: the angle of the ray in which
 * we are measuring the points distance
 *
 * Return: distance between x points of the ray
 * touching vertical side of the tiles
 */

float verticalStepX(float ray_angle)
{
	float step_x;

	/* adjacent size of the triangle */
	step_x = TILE_SIZE;
	step_x *= isRayFacingLeft(ray_angle) ? -1 : 1;

	return (step_x);
}

/**
 * verticalStepY - for each intersection of the ray on vertical tiles,
 * get the opposite side size of the rectangle triangle
 * also named delta y
 *
 * @ray_angle: the angle of the ray in which
 * we are measuring the points distance
 *
 * Return: distance between y points of the ray
 * touching vertical side of the tiles
 */

float verticalStepY(float ray_angle)
{
	float step_y;

	/* opposite size of the triangle */
	step_y = TILE_SIZE * tan(ray_angle);
	step_y *= (isRayFacingUp(ray_angle) && step_y > 0) ? -1 : 1;
	step_y *= (isRayFacingDown(ray_angle) && step_y < 0) ? -1 : 1;

	return (step_y);
}
