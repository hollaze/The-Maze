build:
	gcc src/*.c headers/*.h -o raycast -Wall -Werror -Wextra -std=gnu89 -pedantic `sdl2-config --cflags --libs` -lm;
run:
	./raycast
