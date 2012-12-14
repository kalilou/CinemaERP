#ifndef  FILM_H_INCLUDED
#define  FILM_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Modèele de ce que sera un film */
typedef struct INFO_FILM {
        char titre[100];
        int jour;
		char mois[10];
		int annee;
        char real[50];
        char acteurP[50];
        char acteurS[50];
        int  duree;
        char synopsis[200];
        char version[50];

}info_film;

//structure de film
typedef struct FILM
{
	info_film d;
	struct FILM *next;
}film;

/*Declaration globale du pointeur de chaine film */
film *f_liste;

void f_init(); // initialiser la liste film

/* Fonction permetttant d'ajouter un film dans la liste chainnee creer à partir du chargement du fichiere FILMS */
void ajout_film(char *_titre,char *_mois,char *_real, char *_acteurP,char *_acteurS, char *_synopsis, char *_version,int _duree,int _annee,int _jour);

//rechercher un film deja enregistrer
int f_rechercher(film *tempon);

// FONCTION QUI COMPTE LE NOMBRE DE FILM
int f_compter();

//FONCTION DE RECHERCHER
int f_rechercher_1(char *_titre,char *_real,char *_version);

// FONCTION PERMETTANT LA SUPPRESSION AU DEBUT DE LA LISTE
int  f_supprimer(char *_titre,char *_real,char *_version);


//enregistremement
int f_enregistrer(char *_fichier);


//chargement
int f_chargement(char *_fichier);

//rechercher un film dans le stock
int f_rechercher1(char *titre);

#endif
