SOURCES = $(wildcard *.c)
BINAIRES = $(patsubst %.c,%.o,${SOURCES})

all : main

main : ${BINAIRES}
	gcc $^ -o $@ -lm

main.o : main.c
	gcc -c $^

extraction.o : extraction.c extraction.h
	gcc -c $<

conversion.o : conversion.c conversion.h
	gcc -c $<

affichage.o : affichage.c affichage.h
	gcc -c $<

chargerRep.o : chargerRep.c chargerRep.h
	gcc -c $<

clean : 
	rm *.o main donnees_extraites.txt