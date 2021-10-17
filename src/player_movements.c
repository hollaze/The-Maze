#include <stdio.h>
#include "maze.h"

void update()
{
        player_x += 1;
        player_y += 1;

        printf("X: %d, Y: %d\n", player_x, player_y);
}
