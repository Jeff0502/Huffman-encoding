CC := gcc

SRC := ./*.c

BIN := ./minHeap.o

.PHONY: all clean

all: $(SRC)
	$(CC) $^ -o $(BIN)

run: $(BIN)
	./$^

clean: 
	rm -rf $(BIN)