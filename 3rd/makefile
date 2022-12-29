CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: liftrec liftmem liftbf liftdp

lift.o: src/lift.c src/lift.h
	$(CC) $(CFLAGS) -c src/lift.c

liftrec: lift.o liftrec.o
	$(CC) $(CFLAGS) lift.o liftrec.o -o liftrec

liftrec.o: src/liftrec.c
	$(CC) $(CFLAGS) -c src/liftrec.c

liftmem: lift.o liftmem.o
	$(CC) $(CFLAGS) lift.o liftmem.o -o liftmem

liftmem.o: src/liftmem.c
	$(CC) $(CFLAGS) -c src/liftmem.c

liftbf: lift.o liftbf.o
	$(CC) $(CFLAGS) lift.o liftbf.o -o liftbf

liftbf.o: src/liftbf.c
	$(CC) $(CFLAGS) -c src/liftbf.c

liftdp: lift.o liftdp.o
	$(CC) $(CFLAGS) lift.o liftdp.o -o liftdp

liftdp.o: src/liftdp.c
	$(CC) $(CFLAGS) -c src/liftdp.c

clean:
	rm -f *.o liftrec liftmem liftbf liftdp