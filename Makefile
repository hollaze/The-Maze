build:
	gcc src/*.c headers/*.h -Wall -Werror -Wextra -std=gnu89 -pedantic `sdl2-config --cflags --libs` -lm -o The_Maze;
run:
	./The_Maze
