STD=-std=gnu99
FILE=pr7ex3
LIB=./libpr7

all: $(FILE)
	./$(FILE)
	
$(FILE): $(FILE).o $(LIB).a
	gcc $(STD) $(FILE).o -o $(FILE) -lpthread -lpr7 -L. 


$(FILE).o: $(FILE).c $(LIB).a
	gcc $(STD) -c $(FILE).c -lpthread

$(LIB).a: $(LIB).c
	gcc -g -c -o $(LIB).o $(LIB).c -lpthread
	ar rcs $(LIB).a $(LIB).o

clean:
	rm -rf *.o $(FILE) $(LIB).o $(LIB).a

clean_test:
	rm -f ../test
