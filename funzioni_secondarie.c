#include "funzioni.h"


int confronto_tra_stringhe(char *stringa_1, char *stringa_2){

    int dim1= strlen(stringa_1)-1;
    int dim2= strlen(stringa_2)-1;

    char *s1=malloc(dim1*sizeof(char));
    char *s2=malloc(dim2*sizeof(char));

    strncpy(s1, stringa_1, dim1);
    strncpy(s2, stringa_2, dim2);

    s1[dim1]='\0';
    s2[dim2]='\0';

    return strcasecmp(s1, s2);
}

char* stringa_tutta_minuscola(char *una_stringa){

    char *stringa_minuscola=NULL;
    int i;

    for(i=0; i< strlen(una_stringa); i++){


        if(isupper(una_stringa[i])){

            if(stringa_minuscola==NULL){

                stringa_minuscola=malloc(sizeof(char));
                stringa_minuscola[i]=tolower(una_stringa[i]);

            }else{

                stringa_minuscola=realloc(stringa_minuscola, sizeof(char));
                stringa_minuscola[i]=tolower(una_stringa[i]);
            }

        }else{

            if(stringa_minuscola==NULL){

                stringa_minuscola=malloc(sizeof(char));
                stringa_minuscola[i]=una_stringa[i];

            }else{

                stringa_minuscola= realloc(stringa_minuscola, sizeof(char));
                stringa_minuscola[i]=una_stringa[i];
            }
        }

    }

    stringa_minuscola= realloc(stringa_minuscola, sizeof(char));
    stringa_minuscola[i]='\0';


    return stringa_minuscola;
}
