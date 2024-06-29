CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -Werror
DEST=../build/

all: state_sort state_search clear_state
state_sort:
	$(CC) $(CFLAGS) -o $(DEST)Quest_1 state_sort.c data.c
state_search:
	$(CC) $(CFLAGS) -o $(DEST)Quest_2 state_search.c data.c
clear_state:
	$(CC) $(CFLAGS) -o $(DEST)Quest_3 clear_state.c data.c
clean:
	rm -rf $(DEST)*
rebuild: clean all
clang:
	clang-format -i *.c *.h
	clang-format -n *.c *.h --verbose
cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
leaks:
	leaks -atExit -- $(DEST)Quest_1