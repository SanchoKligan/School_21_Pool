CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -Werror
DEST=../build/

all: build_with_lib
structures.a:
	$(CC) $(CFLAGS) -c stack.c queue.c 
	ar r libstructures.a *.o
	rm -rf *.o
build_with_lib: structures.a
	$(CC) $(CFLAGS) -c tokens_get.c compute.c graph.c
	$(CC) $(CFLAGS) -o $(DEST)graph *.o -L. -lstructures
	rm -rf *.o
clean:
	rm -rf $(DEST)* *.a *.o
rebuild: clean all