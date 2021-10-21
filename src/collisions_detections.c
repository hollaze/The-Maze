#include "../headers/maze.h"
#include <stdlib.h>

int mapHasWallAt(float player_x, float player_y)
{
	int map_grid_index_x, map_grid_index_y;

	if (player_x < 0 || player_x > WINDOW_WIDTH ||
	    player_y < 0 || player_y > WINDOW_HEIGHT)
		return (TRUE);

	map_grid_index_x = floor(player_x / TILE_SIZE);
	map_grid_index_y = floor(player_y / TILE_SIZE);

	return (map[map_grid_index_y][map_grid_index_x] != 0);
}

float normalizeAngle(float angle)
{
	angle = remainder(angle, TWO_PI);

	if (angle < 0)
		angle += TWO_PI;

	return (angle);
}

void castRay(float ray_angle, int strip_id, player_struct player)
{
	int is_ray_facing_down, is_ray_facing_up;
	int is_ray_facing_right, is_ray_facing_left;
	int found_horizontal_wall_hit = FALSE;
	int horizontal_wall_content = 0;

	float intercept_x, intercept_y;
	float step_x, step_y;
	float horizontal_wall_hit_x = 0;
	float horizontal_wall_hit_y = 0;
	float next_horizontal_touch_x;
	float next_horizontal_touch_y;
	float to_check_x, to_check_y;

	ray_angle = normalizeAngle(ray_angle);

	is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
	is_ray_facing_right = ray_angle < (PI / 2) || ray_angle > (1.5 * PI);

	is_ray_facing_up = !is_ray_facing_down;
	is_ray_facing_left = !is_ray_facing_right;

	/* find y coordinates of the closest horizontal grid intersection */
	intercept_y = floor(player.y / TILE_SIZE * TILE_SIZE);
	intercept_y += is_ray_facing_down ? TILE_SIZE : 0;

	/* find x coordinates of the closest horizontal grid intersection */
	intercept_x = player.x + (intercept_y - player.y) / tan(ray_angle);

	/* calulate incrementation of step_x and step_y */
	step_y = TILE_SIZE;
	step_y = (step_y * is_ray_facing_up) ? -1 : 1;

	step_x = TILE_SIZE / tan(ray_angle);
	step_x = step_x * (is_ray_facing_left && step_x > 0) ? -1 : 1;
	step_x = step_x * (is_ray_facing_right && step_x < 0) ? -1 : 1;

	next_horizontal_touch_x = intercept_x;
	next_horizontal_touch_y = intercept_y;

	/* incrementing step_x and step_y until a wall is found */
	while (next_horizontal_touch_x >= 0 &&
	       next_horizontal_touch_x <= WINDOW_WIDTH &&
	       next_horizontal_touch_y >= 0 &&
	       next_horizontal_touch_y <= WINDOW_HEIGHT)
	{
		to_check_x = next_horizontal_touch_x;
		to_check_y = next_horizontal_touch_y + (is_ray_facing_up ? -1 : 0);

		/* Check if there is a wall hit */
		if (mapHasWallAt(to_check_x, to_check_y))
		{
			/* found wall hit */
			horizontal_wall_hit_x = next_horizontal_touch_x;
			horizontal_wall_hit_y = next_horizontal_touch_y;
			horizontal_wall_content =
			    map[(int)floor(to_check_y / TILE_SIZE)][(int)floor(to_check_x / TILE_SIZE)];
			found_horizontal_wall_hit = TRUE;
			break;
		}
		else
		{
			next_horizontal_touch_x += step_x;
			next_horizontal_touch_y += step_y;
		}
	}
}

void castAllRays(player_struct player)
{
	float ray_angle;
	int strip_id;

	ray_angle = (player.rotation_angle - (FOV_ANGLE / 2));

	for (strip_id = 0; strip_id < NUM_RAYS; strip_id++)
	{
		castRay(ray_angle, strip_id, player);
		ray_angle += FOV_ANGLE / NUM_RAYS;
	}
}
