CC = gcc
CFLAGS = -g3 -Wall -Werror -Wextra

OBJ_DIR := ./target/objs
BUILD_DIR := ./target

all: $(BUILD_DIR)/liftrec $(BUILD_DIR)/liftmem $(BUILD_DIR)/liftbf $(BUILD_DIR)/liftdp

$(OBJ_DIR)/%.o: src/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/liftrec: $(OBJ_DIR)/lift.o $(OBJ_DIR)/liftrec.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/lift.o $(OBJ_DIR)/liftrec.o -o $(BUILD_DIR)/liftrec

$(BUILD_DIR)/liftmem: $(OBJ_DIR)/lift.o $(OBJ_DIR)/liftmem.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/lift.o $(OBJ_DIR)/liftmem.o -o $(BUILD_DIR)/liftmem

$(BUILD_DIR)/liftbf: $(OBJ_DIR)/lift.o $(OBJ_DIR)/liftbf.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/lift.o $(OBJ_DIR)/liftbf.o -o $(BUILD_DIR)/liftbf

$(BUILD_DIR)/liftdp: $(OBJ_DIR)/lift.o $(OBJ_DIR)/liftdp.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/lift.o $(OBJ_DIR)/liftdp.o -o $(BUILD_DIR)/liftdp

.PHONY: clean
clean:
	rm -r target