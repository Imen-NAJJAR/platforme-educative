#include <stdio.h>
#include <stdlib.h>
void hashPassword(const char *password, char *hashedPassword) {
    unsigned int hash = 0;
    while (*password) {
        hash = (hash * 31) + *password++;
    }
    sprintf(hashedPassword, "%u", hash);
}
void ajouter_etd()
{
    FILE *file;
    if((file=fopen("fiche_etd.txt","a"))==NULL){
        printf("impossible d'ouvrir le fichier ");
    }
    char id[20], NomPre[50], gr[50], password[50], hashedPassword[50];
    printf("entrer le ID de l'etudiant:\n");
    scanf("%s",&id);
    printf("entrer le nom et le prenom de l'etudiant:\n");
    getchar();
    fgets(NomPre,sizeof(NomPre),stdin);
    NomPre[strcspn(NomPre, "\n")] = '\0';
    printf("le groupe de l'etudiant:\n");
    scanf("%s",&gr);
    printf("Entrez le mot de passe : ");
    scanf("%s", password);
    hashPassword(password,hashedPassword);
    fprintf(file,"ID:  %s\n",id);
    fprintf(file,"Nom et prenom: %s\n",NomPre);
    fprintf(file,"Groupe: %s\n",gr);
    fprintf(file,"Mot de passe (haché): %s\n",hashedPassword);
    fprintf(file, "--------------------------------------\n");
    fclose(file);
    printf("etudiant ajouté avec succès !\n");
}
int main()
{
ajouter_etd();
    return 0;
}
