CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -Werror
DEST=../build/

all: door_struct list_test stack_test
door_struct:
	$(CC) $(CFLAGS) -o $(DEST)Quest_1 dmanager_module.c
list_test:
	$(CC) $(CFLAGS) -o $(DEST)Quest_2 list*.c
stack_test:
	$(CC) $(CFLAGS) -o $(DEST)Quest_3 stack*.c
clean:
	rm -rf $(DEST)*
rebuild: clean all