CC = gcc
CFLAGS = -g3 -Wall -Werror -Wextra

all: figproc convert

figproc: src/figproc.c
	mkdir -p target
	$(CC) $(CFLAGS) -o target/figproc src/figproc.c

convert: src/figproc.c
	mkdir -p target
	$(CC) $(CFLAGS) -DOPTION=1 -o target/convert src/figproc.c

.PHONY: clean
clean:
	rm -r target