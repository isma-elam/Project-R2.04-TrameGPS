all : main

main : main.c extraction.o conversion.o
	gcc extraction.o conversion.o main.c -o main

extraction.o : extraction.c extraction.h
	gcc extraction.c -c

conversion.o : conversion.c conversion.h
	gcc conversion.c -c

clean : 
	rm *.o main