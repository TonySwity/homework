CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2
OBJS = report.o temp_functions.o
BIN = report

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

report.o: report.c temp_functions.h
	$(CC) $(CFLAGS) -c report.c

temp_functions.o: temp_functions.c temp_functions.h
	$(CC) $(CFLAGS) -c temp_functions.c

clean:
	rm -f *.o $(BIN)
