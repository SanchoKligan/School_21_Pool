CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -Werror
SRC=../data_libs/*.c ../data_module/data_process.c ../yet_another_decision_module/decision.c *.c
SRC_STATIC=../data_libs/data_io.c ../data_module/data_process.c ../yet_another_decision_module/decision.c *.c
SRC_DYNAMIC=../data_libs/*.c ../yet_another_decision_module/decision.c *.c
LIB=../data_libs/
PROC=../data_module/
DEST=../../build/

all:
	$(CC) $(CFLAGS) -o $(DEST)Quest_3 $(SRC)
clean:
	rm -rf $(DEST)* $(LIB)*.a $(PROC)*.so *.o
rebuild: clean all
data_stat.a:
	$(CC) $(CFLAGS) -c $(LIB)data_stat.c 
	ar r $(LIB)libdata_stat.a *.o
	rm -rf *.o
build_with_static: data_stat.a
	$(CC) $(CFLAGS) -c $(SRC_STATIC)
	$(CC) $(CFLAGS) -o $(DEST)Quest_5 *.o -L$(LIB) -ldata_stat
	rm -rf *.o
data_process.so:
	$(CC) $(CFLAGS) -c -fPIC $(PROC)data_process.c $(LIB)data_stat.c
	$(CC) $(CFLAGS) -shared -o $(PROC)libdata_process.so *.o
	rm -rf *.o
build_with_dynamic: data_process.so
	$(CC) $(CFLAGS) -c $(SRC_DYNAMIC)
	$(CC) $(CFLAGS) -o $(DEST)Quest_6 *.o -L$(PROC) -ldata_process
	rm -rf *.o