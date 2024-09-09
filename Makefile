CC = gcc
CFLAGS = -Wall
SRC = source/main.c
OUT = build/freakyprint

all: build $(OUT)
build:
	mkdir -p build
$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)
clean:
	rm -f $(OUT)