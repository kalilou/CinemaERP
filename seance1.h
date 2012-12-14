#ifndef  SEANCE_H_INCLUDED
#define  SEANCE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct S_INFO
{
  char nom[30];
  char salle[30];
  char mois[20];
  int jour;
  char version[20];
  int heure;
  int minute;
}s_info;

typedef struct SEANCE
{
  s_info d;
  struct SEANCE *next;
}seance;

//declaration dde la liste des senace de la semaine
seance *liste;



//initialisation de la liste
void s_init();


// saisir toute les seances de la semaine
void s_ajouter(char *_nom,char *_salle,char *_mois,int  _jour,char *_version,int _heure,int _minute);

//rechercher une seance
int s_rechercher();

//reporter une seance
//seance * recuperer(char *jour,int heure);


//enregistremement
int s_enregistrer(char *_fichier);

//chargement
int s_chargement(char *_fichier);

int supprimer_seance( char  *_mois, int _jour , int _heure);


//rechercher une seance
int s_rechercher1(char  *mois, int jour,int heure);

// Fonction qui modifie une seance
int modifier_seance( seance  *ancien , seance  *nouveau );

 //manipulation
void manipuler();

//rechercher une seance
int s_rechercher2(char *mois , int jour );

#endif

