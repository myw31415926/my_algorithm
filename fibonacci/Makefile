# fibonacci Makefile

TARGET = ../_build/fibonacci

INCS =
SRCS = $(wildcard *.c)

CFLAGS = -Wall -g
LFLAGS =

$(TARGET): $(SRCS)
	$(CC) -o $(TARGET) $(SRCS) $(CFLAGS) $(LFLAGS)


.PHONY: clean
clean:
	rm $(TARGET)
