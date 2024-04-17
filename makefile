all : main

main : main.c extraction.o conversion.o affichage.o
	gcc extraction.o conversion.o affichage.o main.c -o main -lm

extraction.o : extraction.c extraction.h
	gcc extraction.c -c

conversion.o : conversion.c conversion.h
	gcc conversion.c -c

affichage.o : affichage.c affichage.h
	gcc affichage.c -c

clean : 
	rm *.o main