CC = gcc
CFLAGS = -Wall -Wextra -I./src
SRC = src/main.c src/timer.c
OBJ = $(SRC:.c=.o)
TARGET = kaizen

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
