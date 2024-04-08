CC := gcc
LD := gcc
CFLAGS := -Wall -pedantic -g -O0

all: sesion9

sesion9: cola.o sesion9.o
	$(LD) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm *.o
	rm sesion9

