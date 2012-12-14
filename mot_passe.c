#include "mot_passe.h"




//FONCTION SAISIR MOT DE PASSE ADMINISTRATION
void mot_de_passe(char *_fichier,char *_identifiant,char *_motpasse)
{
    FILE *fichier = fopen(_fichier,"wb");
    passe *temp3 =Malloc(passe);
    strcpy(temp3->identifiant,_identifiant);
    strcpy(temp3->motpasse,_motpasse);
    fwrite(temp3,sizeof(passe),1,fichier);
    fclose(fichier);
}


//verifiaction du mot de passe par l'admonistratio
int verifier(passe temp)
{
     FILE *fichier = fopen("mot_passe","rb");
     passe *temp3 =Malloc(passe);
     if(fichier == NULL)
     return -1;

     //lecture des donnees a partir du fichier
    fread(temp3,sizeof(passe),1,fichier);

    //fermeture du fichier
    fclose(fichier);

    //comparons les donnees charger du fichier
         if(strcmp(temp3->identifiant,temp.identifiant)  == 0 && strcmp(temp3->motpasse,temp.motpasse)== 0)
         return 1;

      return 0;

}


// changer mot de passe
int changer(char *_fichier,char *_motpasse)
{
    FILE *fichier = fopen(_fichier,"r+");
    char _identifiant[30];

    passe *temp3 = Malloc(passe);
    fread(temp3,sizeof(passe),1,fichier);
    if(strcmp(temp3->motpasse,_motpasse)== 0)
    {
        mot_de_passe("mot_passe.txt",_identifiant,_motpasse);
        return 1;
    }
    else
    return 0;
    fwrite(temp3,sizeof(passe),1,fichier);
    fclose(fichier);
  return 0;
}



// Fonction de modification du mot de passe
int modifier_password( char *ancien_password, char *nouveau_password, char *confirm_password )
{
    // Déclaration d'une structure pour le login et le mot de passe
    passe *q = Malloc(passe );

    // Ouverture du fichier
    FILE* fd = fopen( "mot_passe", "rb+" );

    // Test si le fichier est bien ouvert
    if( fd == NULL )
        return -1;

    // Lecture du login et du mot de passe
    fread( q, sizeof( passe ), 1, fd );

    // Modification de mot de passe
    if( strcmp( q->motpasse, ancien_password ) == 0 && strcmp( nouveau_password, confirm_password ) == 0 )
        {
            strcpy( q->motpasse, nouveau_password );

            // On remonte de la taille de la structure login et mot de passe
            fseek( fd, -sizeof( passe ), SEEK_CUR );

            // On ecrase les anciennes valeurs
            fwrite( q, sizeof( passe ), 1, fd );

            // Fermeture du fichier
            fclose( fd );

            return 1;
        }

    return 0;

}


// Fonction qui test si le mot de passe est valide
int verification ( char *Nom_Fichier, char *passwd )
{
    // Déclaration d'une structure pour le login et le mot de passe
    passe  *q = Malloc( passe );

    // Déclaration et initialisation du poirteur de fichier
    FILE* fd = fopen( "mot_passe", "rb" );

    // Test si le fichier est bien ouverts
    if( fd == NULL )
        return -1;

    // Lecture du login et du mot de passe contenu dans le fichier user.bin
    fread( q, sizeof( passe ), 1, fd );

    // Fermeture du fichier
    fclose( fd );

    // Compare le mot de passe fourni a celui contenu dans le fichier
    if( strcmp( q->motpasse, passwd ) == 0 )
        return 1;

    return 0;
}



