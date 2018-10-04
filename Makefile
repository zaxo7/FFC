all:main.o fonctions.o
	gcc -o main main.o fonctions.o
	rm *.o
	#gnome-terminal -- ./main #
	#./main
main.o:main.c
	gcc -c main.c
fonctions.o:fonctions.c
	gcc -c fonctions.c