build:
	gcc ./src/*.c ./src/*.h -o raycast -Wall -Werror -Wextra -std=gnu89 -pedantic `sdl2-config --cflags --libs`;
run:
	./raycast
