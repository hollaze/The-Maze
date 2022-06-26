#include "../headers/maze.h"
#include <stdlib.h>
#include <limits.h>

/**
 * mapHasWallAt - detect the walls in the map,
 * void is 0, walls are 1
 *
 * @player_x: player in position x
 * @player_y: player in position y
 *
 * Return: 1 if player tries to go outside of the window
 * or touch a wall, otherwise return 0
 */

int mapHasWallAt(float player_x, float player_y)
{
	int map_grid_index_x, map_grid_index_y;

	/* if player tries to go outside the window */
	if (player_x < 0 || player_x > WINDOW_WIDTH ||
	    player_y < 0 || player_y > WINDOW_HEIGHT)
		return (TRUE);

	/* flooring so that the player stay outside of the wall */
	map_grid_index_x = floor(player_x / TILE_SIZE);
	map_grid_index_y = floor(player_y / TILE_SIZE);

	/* if value is different than 0 return 1 else return 0 */
	return (map[map_grid_index_y][map_grid_index_x] != 0);
}

/**
 * distanceBetweenPoints - calculate the distance (of the ray) between
 * the points touching the borders of tiles
 *
 * @x1: the first x point touching the border
 * of the actual tile the ray is pointing on
 * @x2: the second x point touching the border of next tile
 * @y1: the first y point touching border
 * of the actual tile the ray is pointing on
 * @y2: the second y point touching the border of next tile
 *
 * Return: distance of the ray between the x and y points
 */

float distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
	/* Pythagore */
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

/**
 * normalizeAngle - keep the ray_angle between 0 and 2PI
 *
 * @ray_angle: the angle of the ray to normalize
 *
 * Return: the normalized value
 */

float normalizeAngle(float ray_angle)
{
	ray_angle = remainder(ray_angle, TWO_PI);

	if (ray_angle < 0)
		ray_angle = TWO_PI + ray_angle;

	return (ray_angle);
}

/**
 * castRay - cast a ray with wall detection and collision
 * horizontaly and verticaly
 *
 * @ray_angle: the angle of the ray we are casting
 * @strip_id: serves for ray incrementation of the ray
 *
 * Return: void
 */

void castRay(float ray_angle, int strip_id)
{
	setupCollDetect();
	ray_angle = normalizeAngle(ray_angle);

	/* the first horizontal intersection between the */
	/* ray and the horizontal side of the tile touched */
	cd.next_horizontal_touch_x = horizontalInterceptX(ray_angle);
	cd.next_horizontal_touch_y = horizontalInterceptY(ray_angle);

	searchHorizontalWall(ray_angle);

	/* the first vertical intersection between the */
	/* ray and the vertical side of the tile touched */
	cd.next_vertical_touch_x = verticalInterceptX(ray_angle);
	cd.next_vertical_touch_y = verticalInterceptY(ray_angle);

	searchVerticalWall(ray_angle);

	smallestHitDistance(strip_id, ray_angle);
}

/**
 * castAllRays - set the field of view at the center of the
 * player rotation angle,
 * start first ray from the left an create rays from left to right,
 * on ray per pixel of the window (WINDOW_WIDTH)
 * cast all rays per frame: raycasting
 *
 * Return: void
 */

void castAllRays(void)
{
	float ray_angle;
	int strip_id;

	/* start first ray, at the leftmost of the player rotation angle */
	/* set the field of view at the center of the player rotation angle */
	ray_angle = (player.rotation_angle - (FOV_ANGLE / 2));

	/* cast all rays from left to right */
	for (strip_id = 0; strip_id < NUM_RAYS; strip_id++)
	{
		castRay(ray_angle, strip_id);
		ray_angle += FOV_ANGLE / NUM_RAYS;
	}
}
