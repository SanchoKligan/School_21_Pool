CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -Werror
DEST=../build/

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests
strlen_tests:
	$(CC) $(CFLAGS) -DSTRLEN -o $(DEST)Quest_1 *.c
strcmp_tests:
	$(CC) $(CFLAGS) -DSTRCMP -o $(DEST)Quest_2 *.c
strcpy_tests:
	$(CC) $(CFLAGS) -DSTRCPY -o $(DEST)Quest_3 *.c
strcat_tests:
	$(CC) $(CFLAGS) -DSTRCAT -o $(DEST)Quest_4 *.c
strchr_tests:
	$(CC) $(CFLAGS) -DSTRCHR -o $(DEST)Quest_5 *.c
strstr_tests:
	$(CC) $(CFLAGS) -DSTRSTR -o $(DEST)Quest_6 *.c
strtok_tests:
	$(CC) $(CFLAGS) -DSTRTOK -o $(DEST)Quest_7 *.c
clean:
	rm -rf $(DEST)*
rebuild: clean all