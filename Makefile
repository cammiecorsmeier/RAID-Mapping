CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = raid

.PHONY: all clean

all: $(TARGET)

$(TARGET): raid.o
	$(CC) $(CFLAGS) $^ -o $@

raid.o: raid.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) raid.o
