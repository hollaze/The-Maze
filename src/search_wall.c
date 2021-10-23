#include "../headers/maze.h"

void setupCollDetect(void)
{
	/* horizontal */
	cd.found_horizontal_wall_hit = FALSE;
	cd.horizontal_wall_hit_x = 0;
	cd.horizontal_wall_hit_y = 0;
	cd.horizontal_wall_content = 0;
	/* vertical */
	cd.found_vertical_wall_hit = FALSE;
	cd.vertical_wall_hit_x = 0;
	cd.vertical_wall_hit_y = 0;
	cd.vertical_wall_content = 0;
}

void searchHorizontalWall(float ray_angle)
{
	float to_check_x, to_check_y;

	/* incrementing step_x and step_y until a wall is found */
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

void searchVerticalWall(float ray_angle)
{
	float to_check_x, to_check_y;

	/* incrementing step_x and step_y until a wall is found */
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