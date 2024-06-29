CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -Werror
DEST=../build/

all: cipher logging_cipher
cipher:
	$(CC) $(CFLAGS) -o $(DEST)cipher cipher.c
logging_cipher:
	$(CC) $(CFLAGS) -DLOG -o $(DEST)logging_cipher cipher.c logger.c
clean:
	rm -rf $(DEST)*
rebuild: clean all