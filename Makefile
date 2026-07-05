CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

SRC = src/darray.c main.c
OUT = app

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)