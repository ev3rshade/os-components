CC = gcc
CFLAGS = -Wall -Wextra -I./include -g

SRC = src/main.c src/pcb.c src/algorithms.c
OBJ = $(SRC:.c=.o)

scheduler: $(OBJ)
	$(CC) $(CFLAGS) -o scheduler $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o scheduler
