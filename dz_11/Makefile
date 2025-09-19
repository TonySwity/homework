CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: main

main: main.o temp_api.o
	$(CC) $(CFLAGS) -o main main.o temp_api.o

main.o: main.c temp_api.h
	$(CC) $(CFLAGS) -c main.c

temp_api.o: temp_api.c temp_api.h
	$(CC) $(CFLAGS) -c temp_api.c

clean:
	rm -f *.o main
