#ifndef  SALLE_H_INCLUDED
#define  SALLE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Malloc(type) (type *)malloc(sizeof(type))



typedef struct  SALLE_INFO
{
    char salle[20];
    int capacite;
}salle_info;

typedef struct  SALLE
{
    salle_info d;
    struct SALLE *next;
}salle;
salle *_liste;

//initialisation de la liste salle
void init_salle();

//foncton d'ajout
void ajouter_salle(char *_salle,int _capacite);

//chargement
int chargement_salle(char *_fichier);
int enregistrer_salle(char *_fichier);

// FONCTION PERMETTANT LA SUPPRESSION AU DEBUT DE LA LISTE
int supprimer_salle(char *_salle);


// FONCTION QUI COMPTE LE NOMBRE DE SALLE
int compter_salle();

//FONCTION DE RECHERCHER
int rechercher_salle(char *_salle);

#endif

