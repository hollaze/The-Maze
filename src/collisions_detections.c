#include "../headers/maze.h"
#include <stdlib.h>
#include <limits.h>

/**
 * mapHasWallAt - detect the walls in the map,
 * knowing void is 0
 *
 * @player_x: player in position x
 * @player_y: player in position y
 *
 * Return: true if different than 0
 * else return false
 */

int mapHasWallAt(float x, float y)
{
	int map_grid_index_x, map_grid_index_y;

	if (x < 0 || x > WINDOW_WIDTH ||
	    y < 0 || y > WINDOW_HEIGHT)
		return (TRUE);

	map_grid_index_x = floor(x / TILE_SIZE);
	map_grid_index_y = floor(y / TILE_SIZE);

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

float normalizeAngle(float angle)
{
	angle = remainder(angle, TWO_PI);

	if (angle < 0)
		angle = TWO_PI + angle;

	return (angle);
}

void castRay(float ray_angle, int strip_id)
{
	setupCollDetect();
	ray_angle = normalizeAngle(ray_angle);

	/* horizontal ray grid detection */
	cd.next_horizontal_touch_x = horizontalInterceptX(ray_angle);
	cd.next_horizontal_touch_y = horizontalInterceptY(ray_angle);

	searchHorizontalWall(ray_angle);

	/* vertical ray grid detection */
	cd.next_vertical_touch_x = verticalInterceptX(ray_angle);
	cd.next_vertical_touch_y = verticalInterceptY(ray_angle);

	searchVerticalWall(ray_angle);

	smallestHitDistance(strip_id, ray_angle);
}

/**
 * castAllRays - cast all rays per frame: raycasting
 * @player: player struct values
 * @coll_detect: return collision and detections values
 * Return: void
 */

void castAllRays(void)
{
	float ray_angle;
	int strip_id;

	/* start first ray */
	ray_angle = (player.rotation_angle - (FOV_ANGLE / 2));

	/* cast all rays */
	for (strip_id = 0; strip_id < NUM_RAYS; strip_id++)
	{
		castRay(ray_angle, strip_id);
		ray_angle += FOV_ANGLE / NUM_RAYS;
	}
}
