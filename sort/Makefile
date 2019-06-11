# sort_test Makefile

TARGET = ../_build/sort_test

CC = g++
INCS =
SRCS = $(wildcard *.cpp)

CFLAGS = -Wall -g
LFLAGS =

$(TARGET): $(SRCS)
	$(CC) -o $(TARGET) $(SRCS) $(CFLAGS) $(LFLAGS)

.PHONY: clean
clean:
	rm $(TARGET)
