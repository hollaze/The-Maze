#include "../headers/maze.h"

/**
 * searchHorizontalWall - continue to cast the ray until a horizontal
 * wall is found or that it is the end of the window
 *
 * @ray_angle: the angle of the ray being cast
 *
 * Return: void
 */

void searchHorizontalWall(float ray_angle)
{
	float to_check_x, to_check_y;

	/* incrementing the ray distance until a horizontal wall is found */
	while (cd.next_horizontal_touch_x >= 0 &&
	       cd.next_horizontal_touch_x <= WINDOW_WIDTH &&
	       cd.next_horizontal_touch_y >= 0 &&
	       cd.next_horizontal_touch_y <= WINDOW_HEIGHT)
	{
		to_check_x = cd.next_horizontal_touch_x;
		to_check_y = cd.next_horizontal_touch_y +
			     (isRayFacingUp(ray_angle) ? -1 : 0);

		/* Check if there is a wall hit */
		if (mapHasWallAt(to_check_x, to_check_y))
		{
			/* found wall hit */
			cd.horizontal_wall_hit_x = cd.next_horizontal_touch_x;
			cd.horizontal_wall_hit_y = cd.next_horizontal_touch_y;
			cd.horizontal_wall_content =
			map[(int)floor(to_check_y / TILE_SIZE)][(int)floor(to_check_x / TILE_SIZE)];
			cd.found_horizontal_wall_hit = TRUE;
			break;
		}
		else
		{
			cd.next_horizontal_touch_x += horizontalStepX(ray_angle);
			cd.next_horizontal_touch_y += horizontalStepY(ray_angle);
		}
	}
}

/**
 * searchVerticalWall - continue to cast the ray until a vertical
 * wall is found or that it is the end of the window
 *
 * @ray_angle: the angle of the ray being cast
 *
 * Return: void
 */

void searchVerticalWall(float ray_angle)
{
	float to_check_x, to_check_y;

	/* incrementing the ray distance until a vertical wall is found */
	while (cd.next_vertical_touch_x >= 0 &&
	       cd.next_vertical_touch_x <= WINDOW_WIDTH &&
	       cd.next_vertical_touch_y >= 0 &&
	       cd.next_vertical_touch_y <= WINDOW_HEIGHT)
	{
		to_check_x = cd.next_vertical_touch_x +
			     (isRayFacingLeft(ray_angle) ? -1 : 0);
		to_check_y = cd.next_vertical_touch_y;

		/* Check if there is a wall hit */
		if (mapHasWallAt(to_check_x, to_check_y))
		{
			/* found wall hit */
			cd.vertical_wall_hit_x = cd.next_vertical_touch_x;
			cd.vertical_wall_hit_y = cd.next_vertical_touch_y;
			cd.vertical_wall_content =
			map[(int)floor(to_check_y / TILE_SIZE)][(int)floor(to_check_x / TILE_SIZE)];
			cd.found_vertical_wall_hit = TRUE;
			break;
		}
		else
		{
			cd.next_vertical_touch_x += verticalStepX(ray_angle);
			cd.next_vertical_touch_y += verticalStepY(ray_angle);
		}
	}
}

/**
 * smallestHitDistance - determine the smallest hit distance between
 * the horizontal or vertical hit of the ray on the wall or on the end
 * of the window
 *
 * @strip_id: the ray being cast
 * @ray_angle: angle of the ray being cast
 *
 * Return: void
 */

void smallestHitDistance(int strip_id, float ray_angle)
{
	/* calculates horizontal and vertical hit distances and choose smallest one */

	cd.horizontal_hit_distance = cd.found_horizontal_wall_hit
					 ? distanceBetweenPoints(player.x, player.y,
								 cd.horizontal_wall_hit_x,
								 cd.horizontal_wall_hit_y)
					 : FLT_MAX;

	cd.vertical_hit_distance = cd.found_vertical_wall_hit
				       ? distanceBetweenPoints(player.x, player.y,
							       cd.vertical_wall_hit_x,
							       cd.vertical_wall_hit_y)
				       : FLT_MAX;

	if (cd.vertical_hit_distance < cd.horizontal_hit_distance)
	{
		rays[strip_id].distance = cd.vertical_hit_distance;
		rays[strip_id].wall_hit_x = cd.vertical_wall_hit_x;
		rays[strip_id].wall_hit_y = cd.vertical_wall_hit_y;
		rays[strip_id].wall_hit_content = cd.vertical_wall_content;
		rays[strip_id].was_hit_vertical = TRUE;
	}
	else
	{
		rays[strip_id].distance = cd.horizontal_hit_distance;
		rays[strip_id].wall_hit_x = cd.horizontal_wall_hit_x;
		rays[strip_id].wall_hit_y = cd.horizontal_wall_hit_y;
		rays[strip_id].wall_hit_content = cd.horizontal_wall_content;
		rays[strip_id].was_hit_vertical = FALSE;
	}
	rays[strip_id].ray_angle = ray_angle;
	rays[strip_id].ray_facing_down = isRayFacingDown(ray_angle);
	rays[strip_id].ray_facing_up = isRayFacingUp(ray_angle);
	rays[strip_id].ray_facing_left = isRayFacingLeft(ray_angle);
	rays[strip_id].ray_facing_right = isRayFacingRight(ray_angle);
}
