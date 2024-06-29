CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -Werror
DEST=../build/

all: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test
print_module:
	$(CC) $(CFLAGS) -DPM -o $(DEST)Quest_1 main_module_entry_point.c print_module.c
documentation_module:
	$(CC) $(CFLAGS) -DDM -o $(DEST)Quest_2 main_module_entry_point.c documentation_module.c
bst_create_test:
	$(CC) $(CFLAGS) -o $(DEST)Quest_3 bst_create_test.c bst.c
bst_insert_test:
	$(CC) $(CFLAGS) -o $(DEST)Quest_4 bst_insert_test.c bst.c
bst_traverse_test:
	$(CC) $(CFLAGS) -o $(DEST)Quest_5 bst_traverse_test.c bst.c
clean:
	rm -rf $(DEST)*
rebuild: clean all