unrestricted: unrestricted.c
	gcc -Wall -Wextra -Werror -O -o unrestricted unrestricted.c -lm -pthread

restricted: restricted.c
	gcc -Wall -Wextra -Werror -O -o restricted restricted.c

mertsumd: mertsumd.c
	gcc -Wall -Wextra -Werror -O -o mertsumd mertsumd.c

all: mertsumd restricted unrestricted