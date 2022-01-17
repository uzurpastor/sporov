STD=-std=c99
FILE=pr5ex1
SIG=sigin

all: $(FILE) $(SIG)
	./$(FILE)

$(FILE):  $(FILE).o $(SIG).o
	gcc $(STD) $(FILE).o -o $(FILE)

$(SIG).o: $(SIG).c
	gcc $(STD) -c $(SIG).c

$(FILE).o: $(FILE).c
	gcc $(STD) -c $(FILE).c

clean:
	rm -rf *.o *.a\
		$(FILE)\
		$(FILE_2)

clean_test:
	rm -f ../test
