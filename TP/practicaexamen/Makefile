CC := gcc
LD := gcc
CFLAGS := -Wall -pedantic -g -O0

all: examen

examen: examen.o
	$(LD) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm *.o
	rm sesion9

