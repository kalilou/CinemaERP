#ifndef  MOT_PASSE_H_INCLUDED
#define  MOT_PASSE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Malloc(type) (type *)malloc(sizeof(type))

//DEFINITION D UNE STRUCTURE DE MOT DE PASSE
typedef struct MOTPASSE
{
    char identifiant[30];
    char  motpasse[30];
}passe;

//FONCTION SAISIR MOT DE PASSE
//FONCTION SAISIR MOT DE PASSE ADMINISTRATION
void mot_de_passe(char *_fichier,char *_identifiant,char *_motpasse);

//verifiaction du mot de passe
int verification ( char *Nom_Fichier, char *passwd );
// changer mot de passe
int changer(char *_fichier,char *_motpasse);
int modifier_password( char *ancien_password, char *nouveau_password, char *confirm_password );

//verifiaction du mot de passe par l'admonistratio
int verifier(passe temp);


#endif
