CC=gcc
STD=-std=c99

all: pr1e2
	./pr1e2

pr1e2: pr1e2.o ../libpr1.a
	$(CC) $(STD) pr1e2.o -o pr1e2 -l pr1 -L ../ 


pr1e2.o: pr1e2.c
	$(CC) $(STD) -c pr1e2.c

../libpr1.a: ../libpr1.c
	gcc -g -c -o ../libpr1.o ../libpr1.c
	ar rcs ../libpr1.a ../libpr1.o


clean:
	rm -rf *.o pr1e2 ../libpr1.o

clean_test:
	rm -f ../test
