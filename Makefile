# Student Makefile - builds bin/main.exe from src/main.c, src/code.c and src/unity.c
#
#   make        build the program        (bin/main.exe)
#   make run    build and run the tests
#   make clean  remove obj/ and bin/
#   make asan   (Linux / WSL only) build with the sanitizer: bin/main_asan
#
# NOTE: lib/unity.o is NOT used here. It is compiled for the instructor's
# automatic tests on GitHub (Debian). On your computer Unity is compiled from
# src/unity.c into obj/unity.o, for your own system.

CC      = gcc
INC     = include

# Unity must be configured identically for EVERY file that includes it,
# so these -D options are part of CFLAGS (used for main.c, code.c and unity.c).
UNITY_DEFS = -DUNITY_INCLUDE_DOUBLE -DUNITY_DOUBLE_PRECISION=1e-12

CFLAGS  = -Wall -g -Isrc -Ilib -I$(INC) $(UNITY_DEFS)
LDLIBS  = -lm

TARGET  = bin/main.exe

OBJS    = obj/main.o obj/code.o obj/unity.o
HEADERS = $(wildcard $(INC)/*.h)

.PHONY: all run clean asan

all: $(TARGET)

$(TARGET): $(OBJS) | bin
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDLIBS)

# Every object depends on its .c file and on all headers, so a change in
# code.h or unity.h rebuilds everything that needs it.
obj/main.o: src/main.c $(HEADERS) | obj
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

obj/code.o: src/code.c $(HEADERS) | obj
	$(CC) $(CFLAGS) -c src/code.c -o obj/code.o

obj/unity.o: src/unity.c $(HEADERS) | obj
	$(CC) $(CFLAGS) -c src/unity.c -o obj/unity.o

bin:
	mkdir -p bin

obj:
	mkdir -p obj

# The leading "-" tells make to ignore the exit code: the program returns the
# number of failed tests, which is not a build error.
run: $(TARGET)
	-./$(TARGET)

# Linux / WSL only: AddressSanitizer is not available in MinGW on Windows.
asan: | bin
	$(CC) $(CFLAGS) -fsanitize=address,undefined src/main.c src/code.c src/unity.c -o bin/main_asan $(LDLIBS)

clean:
	rm -rf obj bin