# search_test Makefile

TARGET = ../_build/search_test

CC = g++
INCS =
SRCS = $(wildcard *.cpp)

CFLAGS = -Wall -g -I../include/
LFLAGS =

$(TARGET): $(SRCS)
	$(CC) -o $(TARGET) $(SRCS) $(CFLAGS) $(LFLAGS)

.PHONY: clean
clean:
	rm $(TARGET)
