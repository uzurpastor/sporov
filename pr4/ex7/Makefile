STD=-std=c99
FILE=pr4ex7
FILE_1=pr4ex7_1
FILE_2=pr4ex7_2
LIB=libex7

all: $(FILE)
	./$(FILE)

$(FILE): $(FILE_2) $(FILE_1).o $(LIB).a
	gcc $(STD) $(FILE_1).o -o $(FILE) -lex7 -L./

$(FILE_2): $(FILE_2).o $(LIB).a
	gcc $(STD) $(FILE_2).o -o $(FILE_2) -lex7 -L./

$(FILE_1).o: $(FILE_1).c
	gcc $(STD) -c $(FILE_1).c 

$(FILE_2).o: $(FILE_2).c
	gcc $(STD) -c $(FILE_2).c 

$(LIB).a: $(LIB).c
	gcc $(STD) -g -c -o $(LIB).o $(LIB).c
	ar rcs $(LIB).a $(LIB).o

clean:
	rm -rf *.o *.a\
		$(FILE)\
		$(FILE_2)

clean_test:
	rm -f ../test
