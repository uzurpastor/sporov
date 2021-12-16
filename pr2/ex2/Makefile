STD=-std=c99
FILE=pr2ex2
LIB=../libpr2

all: $(FILE)
	

$(FILE): $(FILE).o $(LIB).a
	gcc $(STD) $(FILE).o -o $(FILE) -l pr2 -l m -L ../


$(FILE).o: $(FILE).c
	gcc $(STD) -c $(FILE).c 

$(LIB).a: $(LIB).c
	gcc -g -c -o $(LIB).o $(LIB).c
	ar rcs $(LIB).a $(LIB).o


clean:
	rm -rf *.o $(FILE) $(LIB).o

clean_test:
	rm -f ../test
