CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -Werror
DEST=../build/

all: build_db
build_db:
	$(CC) $(CFLAGS) -o $(DEST)database *.c
clean:
	rm -rf $(DEST)*
rebuild: clean all
clang:
	clang-format -i *.c *.h
	clang-format -n *.c *.h --verbose
cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
leaks:
	leaks -atExit -- $(DEST)database