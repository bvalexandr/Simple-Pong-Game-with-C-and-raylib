CC=gcc
LIBS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -lm

build:
	$(CC) main.c $(LIBS) -o game.out