#include "funzioni.h"

Rec_r *lista_r=NULL;

void inserisci_nuova_ricetta(){

    Rec_r *nuova_r=malloc(sizeof(Rec_r));
    FILE *fp;

    int dim=0;
    int flag;
    char scelta[2];

    printf("Inserisci il nome della ricetta\nInserimento > ");
    gets(nuova_r->nome_r);
    fflush(stdin);

    do{

        flag=1;

        printf("Inserimento ingredienti\n");
        printf("Nome ingrediente > ");
        gets(nuova_r->Rec_i[dim].nome_i);

        fflush(stdin);

        printf("Quantita > ");
        scanf("%d", &nuova_r->Rec_i[dim].quantita);
        dim++;

        fflush(stdin);

        printf("\nVuoi inserire un nuovo ingrediente?(s/n) > ");
        scanf("%c", scelta);

        fflush(stdin);

        if(strchr(scelta, 'n')){

            flag=0;
        }

        system("cls");

    }while(flag != 0);

    nuova_r->n_i=dim;
    nuova_r->next=NULL;

    if(lista_r==NULL){

        lista_r=nuova_r;

    }else{

        Rec_r *curr_r = lista_r;

        while(curr_r->next != NULL){
            curr_r = curr_r->next;
        }

        curr_r->next = nuova_r;

    }

    fp=fopen("LibroRicette.txt", "ab");

    fwrite(lista_r, sizeof(Rec_r), 1, fp);

    fclose(fp);
    free(nuova_r);

}

void stampa_ricettario(){

    FILE *fp=fopen("LibroRicette.txt", "rb");
    Rec_r *una_r=malloc(sizeof(Rec_r));


    if(fp==NULL){
        fprintf(stderr, "Errore scrittura file");
        exit(-1);
    }

    printf("\n RICETTARIO:\n\n");

    while(fread(una_r, sizeof(Rec_r), 1, fp)>0){
        printf(" %c %s.\n", 175,una_r->nome_r);

        /*for(int i=0; i< una_r->n_i ; i++){
            printf("  %c %s %d\n",126 ,una_r->Rec_i[i].nome_i, una_r->Rec_i[i].quantita);
        }*/
    }
    printf("-----------------------------------\n\n");
}

void ricerca_r_per_ingrediente(){

    FILE *fp=fopen("LibroRicette.txt", "rb");
    Rec_r *una_r=malloc(sizeof(Rec_r));
    char *un_ingrediente_search=malloc(sizeof(char));

    if(fp==NULL){
        fprintf(stderr, "Errore scrittura file");
        exit(-1);
    }

    printf("Questo algoritmo permette, tramite inserimento da tastiera di un ingrediente,\n");
    printf("la ricerca di tutte le ricette, associate all'ingrediente scelto\n\n");
    printf("Inserisci ingrediente > ");
    gets(un_ingrediente_search);
    fflush(stdin);

    //system("cls");
    printf("\nCon l'ingrediente scelto [%s] puoi preparare le seguenti ricette:\n\n", un_ingrediente_search);

    while(fread(una_r, sizeof(Rec_r), 1, fp)> 0){
        //un_ingrediente_search una_r->Rec_i[i].nome_i
        //printf("controllo nella ricetta %s\n\n", una_r->nome_r);

        for(int i=0; i< una_r->n_i; i++){

            if(!confronto_tra_stringhe(un_ingrediente_search, una_r->Rec_i[i].nome_i)){

                printf("%c %s\n", 62,una_r->nome_r);
            }
        }

        //printf("---------------------------\n");
    }


    fclose(fp);
}

void trova_ricetta(){

    FILE *fp=fopen("LibroRicette.txt", "rb");
    Rec_r *una_r=malloc(sizeof(Rec_r));
    char *una_ricetta_search=malloc(sizeof(char));

    if(fp==NULL){
        fprintf(stderr, "Errore scrittura file");
        exit(-1);
    }

    printf("Questo algoritmo permette, tramite inserimento del nome di una ricetta,\n");
    printf("la ricerca della ricetta con gli ingredienti associati\n\n");

    printf("Inserisci nome della ricetta > ");
    gets(una_ricetta_search);
    fflush(stdin);

    while(fread(una_r, sizeof(Rec_r), 1, fp) > 0){
        //un_ingrediente_search una_r->Rec_i[i].nome_i

        if(!strcasecmp(una_ricetta_search, una_r->nome_r)){

            printf("\n %s:\n",una_r->nome_r);

            for(int i=0; i< una_r->n_i; i++){

                printf("  %c %s %d\n",126 ,una_r->Rec_i[i].nome_i, una_r->Rec_i[i].quantita);
            }
        }

    }


    fclose(fp);
}
