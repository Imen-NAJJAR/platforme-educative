//executable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
void afficher_cour_td(const char *fichier) {
    int ID;
    printf("Saisir l'identifiant du CourTD � afficher :\n");
    scanf("%d", &ID);

    FILE *f = fopen(fichier, "r");
    if (f == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }

    bool test = false;
    int id;
    char ch[256];
    char titre[256] = "";
    char contenu[256] = "";
    bool trouve = false;

    while (fgets(ch, sizeof(ch), f)) {
        if (strncmp(ch, "ID:", 3) == 0) {
            // Lire l'ID et v�rifier la correspondance
            sscanf(ch, "ID: %d", &id);
            test = (id == ID);
            if (test) {
                trouve = true; // ID trouv�, marquer comme trouv�
                strcpy(titre, "");  // R�initialiser pour �viter les r�sidus
                strcpy(contenu, "");
            }
        } else if ((test) && strncmp(ch, "Titre:", 6) == 0) {
            // Lire le titre
            sscanf(ch, "Titre: %s", titre);
        } else if ((test) && strncmp(ch, "Contenu:", 8) == 0) {
            // Lire le contenu
            sscanf(ch, "Contenu: %s", contenu);
        }
    }

    fclose(f); // Toujours fermer le fichier apr�s utilisation

    if (trouve) {
        printf("Titre : %s\n", titre);
        printf("Contenu : %s\n", contenu);
    } else {
        printf("Aucun CourTD trouv� avec l'ID %d.\n", ID);
    }
}

int main() {
    afficher_cour_td("ficher.txt");
    return 0;
}
