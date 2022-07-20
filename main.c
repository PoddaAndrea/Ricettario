#include "funzioni.h"

int main()
{
    int scelta;

    do{
        printf("RICETTARIO 1.0\n");
        printf("1)Inserisci una ricetta.");
        printf("\n2)Visualizza il ricettario");
        printf("\n3)Ricerca ricetta");
        printf("\n4)Trova ricette da ingrediente");
        printf("\n0)Esci");
        printf("\nScelta >");
        scanf("%d", &scelta);

        switch(scelta){
        case 1:
            fflush(stdin);
            system("cls");
            inserisci_nuova_ricetta();
            break;
        case 2:
            stampa_ricettario();
            break;
        case 3:
            fflush(stdin);
            system("cls");
            stampa_ricettario();
            printf("\n\n");
            trova_ricetta();
            break;
        case 4:
            fflush(stdin);
            system("cls");
            ricerca_r_per_ingrediente();
            break;
        case 0:
            scelta=-1;
            break;
        default:
            system("cls");
            printf("ATTENZOINE: Hai inserito un opzione non valida\n\n");
            break;
        }

    }while(scelta != -1);

    return 0;
}
