PROJECT := sbr
BINARY := $(PROJECT)
CC := gcc
CFLAGS := -Wall -pedantic -g
LDFLAGS := -lm

SRC := $(wildcard src/*.c)
HDR := $(wildcard src/*.h)
OBJ := $(patsubst %.c,%.o,$(SRC))

all: $(BINARY)

$(BINARY): $(OBJ)
	$(CC) -o $(BINARY) $(OBJ) $(LDFLAGS)

%.o: %.c $(HDR)
	$(CC) -o $@ -c $(CFLAGS) $<

.PHONY: clean
clean:
	rm -f $(BINARY) src/*.o

