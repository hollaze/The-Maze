#include "../headers/maze.h"

/**
 * isRayFacingDown - function used to check if user is facing down
 *
 * @ray_angle: the checked angle
 *
 * Return: the ray angle
 */

int isRayFacingDown(float ray_angle)
{
	int is_ray_facing_down;

	is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
	return (is_ray_facing_down);
}

/**
 * isRayFacingUp - function used to check if user is facing up
 *
 * @ray_angle: the checked angle
 *
 * Return: the ray angle
 */

int isRayFacingUp(float ray_angle)
{
	int is_ray_facing_up;

	is_ray_facing_up = isRayFacingDown(ray_angle);
	return (!is_ray_facing_up);
}

/**
 * isRayFacingRight - function used to check if user is facing right
 *
 * @ray_angle: the checked angle
 *
 * Return: the ray angle
 */

int isRayFacingRight(float ray_angle)
{
	int is_ray_facing_right;

	is_ray_facing_right = ray_angle < PI / 2 || ray_angle > 1.5 * PI;
	return (is_ray_facing_right);
}

/**
 * isRayFacingLeft - function used to check if user is facing left
 *
 * @ray_angle: the checked angle
 *
 * Return: the ray angle
 */

int isRayFacingLeft(float ray_angle)
{
	int is_ray_facing_left;

	is_ray_facing_left = isRayFacingRight(ray_angle);
	return (!is_ray_facing_left);
}
