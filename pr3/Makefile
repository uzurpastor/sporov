STD=-std=c99
FILE=pr3ex1
LIB=libpr3

all: $(FILE)
	

$(FILE): $(FILE).o $(LIB).a
	gcc $(STD) $(FILE).o -o $(FILE) -lpr3 -L./


$(FILE).o: $(FILE).c
	gcc $(STD) -c $(FILE).c 

$(LIB).a: $(LIB).c
	gcc -g -c -o $(LIB).o $(LIB).c
	ar rcs $(LIB).a $(LIB).o


clean:
	rm -rf *.o $(FILE) $(LIB).o

clean_test:
	rm -f ../test
