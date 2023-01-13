CC = gcc
CFLAGS = -g3 -Wall -Werror -Wextra

SRC_DIR = src
OBJ_DIR = target/objs
BUILD_DIR = target
SRC = liftrec.c liftmem.c liftbf.c liftdp.c
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o)) $(OBJ_DIR)/lift.o
TARGETS = $(addprefix $(BUILD_DIR)/,$(SRC:.c=))

.PHONY: all clean

all: $(TARGETS)

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/lift.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGETS): $(BUILD_DIR)/%: $(OBJ_DIR)/%.o $(OBJ_DIR)/lift.o
	$(CC) $(OBJ_DIR)/lift.o $< -o $@

clean:
	rm -rf target