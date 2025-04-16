#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50 // Nombre maximal d'animaux dans le refuge
#define TAILLE_MAX 100

// Définition du type animal
typedef struct {
    unsigned short id;//pourquoi une déclaration pareille
    char nom[30];
    char espece[30];
    int anneeNaissance;
    float poids;
    char commentaire[50];
} tAnimal;

// Définition de la structure contenant le tableau
typedef struct {
    int occup;
    tAnimal* ptrAnimal;
} tabAnimaux;

// Fonction pour compter le nombre de lignes dans un fichier
int compterAnimaux(const char* filename) {// pas compris
    FILE* f = fopen(filename, "r");
    int nb_lignes = 0;
    char ligne[TAILLE_MAX];

    if (f == NULL) {
        printf("Fichier introuvable\n");
        return 0;
    }

    while (fgets(ligne, TAILLE_MAX, f) != NULL) {
        nb_lignes++;
    }

    fclose(f);
    return nb_lignes;
}

// Fonction pour charger les données du fichier dans une structure tabAnimaux
tabAnimaux load_file(const char* filename) {
    FILE* f = fopen(filename, "r");
    tabAnimaux tab;
    tab.occup = 0;
    tab.ptrAnimal = NULL;// pas compris

    if (f == NULL) {
        printf("Fichier %s introuvable !\n", filename);
        return tab;
    }

    tab.occup = compterAnimaux(filename);
    tab.ptrAnimal = (tAnimal*)malloc(tab.occup * sizeof(tAnimal));

    for (int i = 0; i < tab.occup; i++) {
        fscanf(f, "%hu %s %s %d %f %s",
               &tab.ptrAnimal[i].id,
               tab.ptrAnimal[i].nom,
               tab.ptrAnimal[i].espece,
               &tab.ptrAnimal[i].anneeNaissance,
               &tab.ptrAnimal[i].poids,
               tab.ptrAnimal[i].commentaire);
    }

    fclose(f);
    return tab;
}

// Fonction d'affichage des animaux
void afficherAnimaux(const tabAnimaux tab) {
    printf("Nombre d'animaux : %d\n", tab.occup);
    printf("-----------------------------\n");

    for (int i = 0; i < tab.occup; i++) {
        tAnimal a = tab.ptrAnimal[i];
        printf("ID : %hu; ", a.id);
        printf("Nom : %s; ", a.nom);
        printf("Espece : %s; ", a.espece);
        printf("Annee de naissance : %d; ", a.anneeNaissance);
        printf("Poids : %.2f kg; ", a.poids);
        printf("Commentaire : %s;\n", a.commentaire);
        printf("-----------------------------\n");
    }
}

// Fonction d'ajout d'un nouvel animal dans le fichier
void ajouterAnimal(const char* filename) {
    int nbAnimaux = compterAnimaux(filename);
    if (nbAnimaux >= N) {
        printf("Limite de 50 animaux atteinte.\n");
        return;
    }

    tAnimal nvAnimal;
    nvAnimal.id = nbAnimaux + 1;

    printf("Nom : ");
    scanf("%s", nvAnimal.nom);
    printf("Espece : ");
    scanf("%s", nvAnimal.espece);
    printf("Annee de naissance : ");
    scanf("%d", &nvAnimal.anneeNaissance);
    printf("Poids : ");
    scanf("%f", &nvAnimal.poids);
    printf("Commentaire : ");
    scanf("%s", nvAnimal.commentaire);

    FILE* f = fopen(filename, "a");
    if (f == NULL) {
        printf("Fichier introuvable.\n");
        return;
    }

    fprintf(f, "\n%hu %s %s %d %.2f %s",
            nvAnimal.id,
            nvAnimal.nom,
            nvAnimal.espece,
            nvAnimal.anneeNaissance,
            nvAnimal.poids,
            nvAnimal.commentaire);

    fclose(f);
}

// Fonction principale
int main() {
    const char* nom_fichier = "file.txt";

    printf("Avant ajout d'un nouvel animal\n");
    tabAnimaux refuge = load_file(nom_fichier);
    afficherAnimaux(refuge);
    free(refuge.ptrAnimal);

    ajouterAnimal(nom_fichier);

    printf("Apres ajout d'un nouvel animal\n");
    refuge = load_file(nom_fichier);
    afficherAnimaux(refuge);
    free(refuge.ptrAnimal);

    return 0;
}
