#ifndef  EMPLOYE_H_INCLUDED
#define  EMPLOYE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define Malloc(type) (type *)malloc(sizeof(type))
#define ESC 27

//DIFINITION DE LA STRUCTURE EMPLOYE
typedef struct E_info
{
	char nom[30];
	char prenom[30];
	char adresse[30];
	char  tel[20];
	char cin[15];
	char status[30];
}info;
//structure  employe
typedef struct EMPLOYE
{
    info d;
    struct EMPLOYE *next;
}employe;

//declaration globale
employe *e_liste;

//initilisation de la liste
void e_initialiser();


//PROTOTYPE DE LA FONCTION SERVANT A SAISIR LES INFORMATION CONCERNANT L EMPLOYE
void e_ajouter(char *_nom,char *_prenom,char *_adresse,char *_cin,char *_tel,char *_status);


//HISTORIQUE DES EMPLOYES DU CINEMA
void e_historique();

// FONCTION QUI COMPTE LE NOMBRE D EMPLOYE
int e_compter();


// FONCTION PERMETTANT LA SUPPRESSION AU DEBUT DE LA LISTE
int  e_licencie(char *_cin);


//FONCTION DE RECHERCHER
int e_rechercher(char *_cin);
//enregistremement
void e_enregistrer(char *_fichier);

//chargement
int e_chargement(char *_fichier);


// Fonction qui lit unemploye
employe* Lire_employe( char *Nom_Fichier, char *cin );



// FONCTION QUI ENGLOBE TOUTES LES AUTRES FONCTIONS QUE L'UTILISATEURS AURA AVOIR BESOIN:
void e_manipulation();


#endif
