CC = gcc
FL = -Wall -Wextra -Werror -std=c11

all: re converter

converter: main.c
	$(CC) $(FL) main.c -o converter

clean:
	rm -rf converter

re: clean

.PHONY: all re clean