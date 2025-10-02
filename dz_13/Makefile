CC      = cc
CFLAGS  = -Wall -Wextra -Wpedantic -std=c11 -O2
BIN     = main
OBJS    = main.o temp_api.o utils.o

.PHONY: all clean run

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(OBJS) $(BIN)
