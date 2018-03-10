# Makefile entry

TARGET_DIRS = _build/
ALL_DIRS    = $(shell ls -d */)
ALL_DIRS   := $(filter-out $(TARGET_DIRS), $(ALL_DIRS))

CC := gcc

all:
	mkdir -p $(TARGET_DIRS)
	@for dir in $(ALL_DIRS); do \
		echo $$dir; \
		(cd $$dir; make); \
	done

.PHONY: clean
clean:
	@for dir in $(ALL_DIRS); do \
		echo $$dir; \
		(cd $$dir; make clean); \
	done
