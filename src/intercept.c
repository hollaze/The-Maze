#include "../headers/maze.h"

float horizontalInterceptY(float ray_angle)
{
	float intercept_y;

	/* find y coordinates of the closest horizontal grid intersection */
	intercept_y = floor(player.y / TILE_SIZE) * TILE_SIZE;
	intercept_y += isRayFacingDown(ray_angle) ? TILE_SIZE : 0;

	return (intercept_y);
}

float horizontalInterceptX(float ray_angle)
{
	float intercept_x, intercept_y;

	intercept_y = horizontalInterceptY(ray_angle);

	/* find x coordinates of the closest horizontal grid intersection */
	intercept_x = player.x + (intercept_y - player.y) / tan(ray_angle);

	return (intercept_x);
}

float verticalInterceptX(float ray_angle)
{
	float intercept_x;

	intercept_x = floor(player.x / TILE_SIZE) * TILE_SIZE;
	intercept_x += isRayFacingRight(ray_angle) ? TILE_SIZE : 0;

	return (intercept_x);
}

float verticalInterceptY(float ray_angle)
{
	float intercept_y, intercept_x;

	intercept_x = verticalInterceptX(ray_angle);

	intercept_y = player.y + (intercept_x - player.x) * tan(ray_angle);

	return (intercept_y);
}
