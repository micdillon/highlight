P=hl
OBJECTS=
CFLAGS=-g -Wall -O3
LDLIBS=
CC=clang

$(P): $(OBJECTS)

clean:
	rm $(P) 
	rm -rf *.dSYM
