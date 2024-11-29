#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct
{
    int jour,mois,annee;
}date;
void ajouter_test(const char *file)
{
    FILE *f;
    if((f=fopen(file,"w")==NULL)){
       printf("impossible d'ouvrir le fichier");
       return;
    }
    int id;
    printf("saisir l'identifiant du test: ");
    scanf("%d",&id);
    fprintf(f,"DI: %d\n",id);
    date D;
    printf("saisir la date limite pour rende le test: ");
    scanf("%d %d %d",&D.jour,&D.mois,&D.annee);
    fprintf(f,"Date limite: %d/%d/%d\n",D.jour,D.mois,D.annee);
    while (getchar() != '\n');
    char ch[256];
    printf("saisir le contenu du test: ");
    fgets(ch,sizeof(ch),stdin);
    size_t len = strlen(ch);
    if (len > 0 && ch[len - 1] == '\n') {
        ch[len - 1] = '\0';
    }
    fprintf(f,"Contenu: %s\n",ch);
    fclose(f);
    printf("test ajouté avec sucsée.");

}

int main()
{
    ajouter_test("ajout");
    return 0;
}
//il ne s'affiche rien meme si le fichier existe
//le programme executable mais les information ne se stocke pas
