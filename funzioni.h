#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Rec_r{

    char nome_r[41];

    struct{

        char nome_i[31];
        int quantita;

    }Rec_i[30];

    int n_i;

    struct Rec_r *next;

}Rec_r;


#ifndef FUNZIONI_H_INCLUDED
#define FUNZIONI_H_INCLUDED

void inserisci_nuova_ricetta();
void stampa_ricettario();
void ricerca_r_per_ingrediente();
char* stringa_tutta_minuscola(char *una_stringa);
int confronto_tra_stringhe(char *stringa_1, char *stringa_2);
void trova_ricetta();

#endif // FUNZIONI_H_INCLUDED

