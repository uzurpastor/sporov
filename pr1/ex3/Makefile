CC=gcc
STD=-std=c99

all: pr1e3
	./pr1e3

pr1e3: pr1e3.o ../libpr1.a
	$(CC) $(STD) pr1e3.o -o pr1e3 -l pr1 -L ../ 


pr1e3.o: pr1e3.c
	$(CC) $(STD) -c pr1e3.c

../libpr1.a: ../libpr1.c
	gcc -g -c -o ../libpr1.o ../libpr1.c
	ar rcs ../libpr1.a ../libpr1.o


clean:
	rm -rf *.o pr1e3 ../libpr1.o

clean_test:
	rm -f ../test
