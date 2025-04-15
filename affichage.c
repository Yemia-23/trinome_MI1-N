#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define MAX_ANIMAUX 50

typedef struct {
    int id;
    char nom[30];
    char espece[15];
    int annee_naissance;
    float poids;
    char commentaire[100];
}Animal;

// Fonction pour lire un entier avec scanf
int lireEntier(const char *message) {
    int valeur;
    printf("%s", message); // Affiche le message
    if (scanf("%d", &valeur) != 1) {
        // La lecture a échoué
        printf("Erreur : saisie invalide. Veuillez entrer un nombre entier.\n");
        // Vide le tampon d'entrée
        while (getchar() != '\n');
        return -1; // Retourne -1 pour indiquer une erreur
    }
    // Vide le tampon d'entrée
    while (getchar() != '\n');
    return valeur; // Retourne la valeur lue
}

// Fonction pour lire un flottant avec scanf
float lireFlottant(const char *message) {
    float valeur;
    printf("%s", message);
    if (scanf("%f", &valeur) != 1) {
        printf("Erreur : saisie invalide. Veuillez entrer un nombre.\n");
        while (getchar() != '\n');
        return -1.0f; // Retourne -1.0 pour indiquer une erreur
    }
    while (getchar() != '\n');
    return valeur;
}

// Fonction pour lire un caractère avec scanf
void lireChaine(const char *message, char *chaine, int taille ) 
{
    printf("%s", message);
    if (scanf("%s", chaine) != 1) {
        printf("Erreur : saisie invalide.\n");
        while (getchar() != '\n');
        chaine[0] = '\0'; // Chaîne vide en cas d'erreur
    } else {
        while (getchar() != '\n');
    }
}



void ajouterAnimal(FILE *fichier) {
    Animal nouvelAnimal;

    printf("L'identifiant de l'animal : ");
    if (scanf("%d", &nouvelAnimal.id) != 1) return;
    while (getchar() != '\n');

    printf("Nom de l'animal : ");
    if (scanf("%s", nouvelAnimal.nom) != 1) return;
     while (getchar() != '\n');

    printf("L'annee de naissance de l'animal : ");
    if (scanf("%d", &nouvelAnimal.annee_naissance) != 1) return;
     while (getchar() != '\n');

    printf("L'espece de l'animal : ");
    if (scanf("%s", nouvelAnimal.espece) != 1) return;
     while (getchar() != '\n');

    printf("Le poids de l'animal : ");
    if (scanf("%f", &nouvelAnimal.poids) != 1) return;
     while (getchar() != '\n');

    printf("Le commentaire : ");
    if (scanf("%s", nouvelAnimal.commentaire) != 1) return;
     while (getchar() != '\n');

    fprintf(fichier, "%d,%s,%d,%s,%f,%s\n", nouvelAnimal.id, nouvelAnimal.nom, nouvelAnimal.annee_naissance, nouvelAnimal.espece, nouvelAnimal.poids, nouvelAnimal.commentaire);

    printf("Animal ajouté avec succès !\n");
}

void rechercherAnimal() {
    printf("rechercher animal\n");
}

void adopterAnimal() {
    printf("adopter animal\n");
}

void afficherMenu(FILE *fichier) {
    fprintf(fichier, "\n--- Menu ChenYl-Tech ---\n");
    fprintf(fichier, "1. Ajouter un animal\n");
    fprintf(fichier, "2. Rechercher un animal\n");
    fprintf(fichier, "3. Adopter un animal\n");
    fprintf(fichier, "4. Quitter\n");
    fprintf(fichier, "Votre choix : ");
}

int main() {
    int choix;
    FILE *fichierMenu = fopen("Menu.txt", "w");
    FILE *fichierAnimaux = fopen("animaux.txt", "a");

    if (fichierMenu == NULL || fichierAnimaux == NULL) {
        printf("Erreur : Impossible d'ouvrir les fichiers.\n");
        return 1;
    }

    do {
        afficherMenu(fichierMenu);
        printf("Votre choix : ");
        scanf("%d", &choix);
        while (getchar() != '\n');

        switch (choix) {
            case 1:
                ajouterAnimal(fichierAnimaux);
                break;
            case 2:
                rechercherAnimal();
                break;
            case 3:
                adopterAnimal();
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 4);

    fclose(fichierMenu);
    fclose(fichierAnimaux);
    return 0;
}