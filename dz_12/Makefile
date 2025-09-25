# === Makefile ===
CC      = cc
CFLAGS  = -Wall -Wextra -Wpedantic -std=c11 -O2
LDFLAGS =

# Исполняемый файл
BIN = main

# Объектные файлы
OBJS = main.o temp_api.o utils.o

.PHONY: all clean run

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Правила компиляции
main.o: main.c temp_api.h utils.h
	$(CC) $(CFLAGS) -c $<

temp_api.o: temp_api.c temp_api.h
	$(CC) $(CFLAGS) -c $<

utils.o: utils.c utils.h temp_api.h
	$(CC) $(CFLAGS) -c $<

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(OBJS) $(BIN)
