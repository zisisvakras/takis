CC = gcc
CFLAGS = -g3 -Wall -Werror -Wextra

all: mertsumd restricted unrestricted

unrestricted: src/unrestricted.c
	mkdir -p target
	$(CC) $(CFLAGS) -o target/unrestricted src/unrestricted.c -lm -pthread

restricted: src/restricted.c
	mkdir -p target
	$(CC) $(CFLAGS) -o target/restricted src/restricted.c

mertsumd: src/mertsumd.c
	mkdir -p target
	$(CC) $(CFLAGS) -o target/mertsumd src/mertsumd.c

.PHONY: clean
clean:
	rm -r target