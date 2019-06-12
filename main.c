#include <stdio.h>
#include <stdlib.h>
// aplicatia care sa utilizeze fseek pentru a inlocui spatiul cu un alt caracter
int main()
{
    FILE *fisier;
    fisier = fopen ("text.txt", "w+"); // a+ pune cursoriul la sfarsitul fisierului, poate sa citeasca dar sa scrie poate doar la sfarsit, fisierul trebuie sa existe
    fputs ("Ana are mere.", fisier);

    fseek (fisier,0, SEEK_SET);

    char caracter;

    do {
        caracter = getc (fisier);
        if (caracter == ' '){
            fseek (fisier,-1, SEEK_CUR);
            fputs("_",fisier);
           fseek (fisier,0,SEEK_SET);
        }

    }while (caracter != EOF);

    fclose(fisier);

    return 0;
}

