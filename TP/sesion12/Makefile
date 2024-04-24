CC := gcc
LD := gcc
CFLAGS := -g -O0 -Wall -pedantic

all: sesion12

sesion12: bt.o sesion12.o
	$(LD) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm *.o
	rm sesion12

