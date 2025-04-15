#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct {
    int nb_id;//numéro d'identification
    char nom;
    char espèces[30];//à revoir
    int annee;
    int poids;
    char com[100];//commentaire
    }animal;
    
typedef struct {
    animal Animal[50];
    int nb_animal;//nombre d'animaux présents dans le refuge
    }refuge;


void vide_buffer();
