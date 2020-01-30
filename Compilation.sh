gcc -c tablette.c tablette.h -lMLV
gcc -c jouer.c jouer.h
gcc -c affichage.c affichage.h -lMLV
gcc -c main.c 
gcc main.o affichage.o jouer.o tablette.o  -lMLV
rm *.o
rm *.h.gch
