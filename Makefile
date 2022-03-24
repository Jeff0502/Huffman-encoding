CC := gcc

CFLAGS := -g

SRC := ./*.c

BIN := ./minHeap.o

.PHONY: all clean

all: $(SRC)
	$(CC) $^ $(CFLAGS) -o $(BIN)

run: $(BIN)
	./$^

clean: 
	rm -rf $(BIN)