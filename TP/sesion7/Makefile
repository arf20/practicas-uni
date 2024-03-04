CC := gcc
LD := gcc
CFLAGS := 

all: sesion7

sesion7: bombo.o sesion7.o
	$(LD) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm *.o
	rm sesion7

