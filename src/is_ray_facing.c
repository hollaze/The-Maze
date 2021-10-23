#include "../headers/maze.h"

int isRayFacingDown(float ray_angle)
{
        int is_ray_facing_down;

        is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
        return (is_ray_facing_down);
}

int isRayFacingUp(float ray_angle)
{
        int is_ray_facing_up;

        is_ray_facing_up = isRayFacingDown(ray_angle);
        return (!is_ray_facing_up);
}

int isRayFacingRight(float ray_angle)
{
        int is_ray_facing_right;

        is_ray_facing_right = ray_angle < 0.5 * PI || ray_angle > 1.5 * PI;
        return (is_ray_facing_right);
}

int isRayFacingLeft(float ray_angle)
{
        int is_ray_facing_left;

        is_ray_facing_left = isRayFacingRight(ray_angle);
        return (!is_ray_facing_left);
}
