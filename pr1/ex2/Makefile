CC=gcc
STD=-std=c99

all: pr1e2
	./pr1e2

pr1e2: pr1e2.o
	$(CC) $(STD) pr1e2.o ../libpr1.h -o pr1e2
pr1e2.o: pr1e2.c
	$(CC) $(STD) -c pr1e2.c

clean:
	rm -rf *.o pr1e2 