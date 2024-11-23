#include <stdio.h>
#include <stdlib.h>
void rendre_dvr(const char *compte_rendu) {
    FILE *fichier ;
    fichier = fopen(compte_rendu,"w");
    if (fichier == NULL) {
        printf("impossible d'ouvrir le fichier");
        return;

    }
    char ch[256];
    printf("mettre votre reponse :\n");
    fgets(ch,sizeof(ch),stdin);
    fputs(ch,fichier);
    fclose(fichier);
}
int main()
{
    rendre_dvr("fichier.txt");
    return 0;
}
