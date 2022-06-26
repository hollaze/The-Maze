#include "../headers/maze.h"

/**
 * horizontalInterceptY - intercept the first horizontal point intersection
 * from the ray with the grid, give its y coordinates
 *
 * @ray_angle: the angle of the ray
 *
 * Return: its y coordinates
 */

float horizontalInterceptY(float ray_angle)
{
	float intercept_y;

	/* find y coordinates of the closest horizontal grid intersection */
	intercept_y = floor(player.y / TILE_SIZE) * TILE_SIZE;
	intercept_y += isRayFacingDown(ray_angle) ? TILE_SIZE : 0;

	return (intercept_y);
}

/**
 * horizontalInterceptX - from the y position of the first horizontal
 * point intersection, get the x position of the point
 *
 * @ray_angle: the angle of the ray
 *
 * Return: x coordinates of the point
 */

float horizontalInterceptX(float ray_angle)
{
	float intercept_x, intercept_y;

	intercept_y = horizontalInterceptY(ray_angle);
	/* player.x -> get player in x position */
	/* (intercept_y - player.y) -> adjacent size of the triangle */
	/* (intercept_y - player.y) / tan(ray_angle) -> */
	/* opposite side size of the triangle */
	intercept_x = player.x + (intercept_y - player.y) / tan(ray_angle);

	return (intercept_x);
}

/**
 * verticalInterceptX - intercept the first vertical point intersection
 * from the ray with the grid, give its x coordinates
 *
 * @ray_angle: the angle of the ray
 *
 * Return: x coordinates of the point
 */

float verticalInterceptX(float ray_angle)
{
	float intercept_x;

	intercept_x = floor(player.x / TILE_SIZE) * TILE_SIZE;
	intercept_x += isRayFacingRight(ray_angle) ? TILE_SIZE : 0;

	return (intercept_x);
}

/**
 * verticalInterceptY - from the x position of the first horizontal
 * point intersection, get the y position of the point
 *
 * @ray_angle: the angle of the ray
 *
 * Return: y coordinates of the point
 */

float verticalInterceptY(float ray_angle)
{
	float intercept_y, intercept_x;

	intercept_x = verticalInterceptX(ray_angle);
	/* Opposite of explanation in horizontalInterceptX */
	intercept_y = player.y + (intercept_x - player.x) * tan(ray_angle);

	return (intercept_y);
}
