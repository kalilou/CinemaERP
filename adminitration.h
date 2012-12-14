#ifndef  ADMINITRATION_H_INCLUDED
#define  ADMINITRATION_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define Malloc(type) (type *)malloc(sizeof(type))
#define ESC 27



typedef struct A_MIN
{
    char nom[30];
    char prenom[30];
    char status[30];
    char adresse[100];
    char cin[10];
    char tel[20];

}a_min;
typedef struct ADMINISTRATION
{
    a_min d;
    struct ADMINISTRATION *next;

}administration;

//declaration globale
administration *a_liste;

//initilisation de la liste
void a_initialiser();

//DEFINITION DE LA FONCTION DE SAISIE DU STAFF ADMINISTRATION
void a_ajouter(char *_nom,char *_prenom,char *_adresse,char *_cin,char *_tel,char *_status);


// FONCTION PERMETTANT LA SUPPRESSION ADMINISTRATION DE LA LISTE
void a_renouveller(char *_nom,char *_prenom,char *_status,char *_ancien_status);


// FONCTION QUI COMPTE LE NOMBRE D EMPLOYE
int a_compter();

//enregistremement
void a_enregistrer(char *_fichier);

//chargement
int a_chargement(char *_fichier);

// FONCTION PERMETTANT LA SUPPRESSION AU DEBUT DE LA LISTE
void a_licencie(char *_status);


int a_rechercher(char *_cin);
#endif






