CC=gcc
STD=-std=c99

all: pr1e0
	./pr1e0

pr1e0: pr1e0.o
	$(CC) $(STD) pr1e0.o ../libpr1.c -o pr1e0

pr1e0.o: pr1e0.c
	$(CC) $(STD) -c pr1e0.c

clean:
	rm -rf *.o pr1e0 