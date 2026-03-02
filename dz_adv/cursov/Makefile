CC      = gcc
CFLAGS  = -std=c11 -O2 -Wall -Wextra -pedantic
LDFLAGS = -lm

OBJS = main.o methods.o funcs.o tests.o
BIN  = area

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

main.o: main.c methods.h funcs.h tests.h
methods.o: methods.c methods.h
funcs.o: funcs.c funcs.h
tests.o: tests.c tests.h methods.h

clean:
	rm -f $(BIN) $(OBJS)
