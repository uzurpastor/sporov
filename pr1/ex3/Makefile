CC=gcc
STD=-std=c99

all: pr1e3
	./pr1e3

pr1e3: pr1e3.o
	$(CC) $(STD) pr1e3.o ../libpr1.h -o pr1e3
pr1e3.o: pr1e3.c
	$(CC) $(STD) -c pr1e3.c

clean:
	rm -rf *.o pr1e3 system_out
