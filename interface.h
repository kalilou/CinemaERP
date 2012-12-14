#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include<stdlib.h>
#include<gtk/gtk.h>
#include "employe.h"
#include <glib/gprintf.h>

GtkWidget *fenetre;

// Un timer
int timer;


void info_employe(void);

void fenetre_employe(void);

//void menu(void);

GtkWidget * menu(void);
// Boîte de dialogue erreur
void message_erreur( GtkWindow *fparent, char *format, ... );


// boîte de base pour les autres boîtes de dialogue
void afficher_message( GtkWindow *fparent, GtkMessageType type, GtkButtonsType button, char *titre, const gchar *format, va_list va );

void OnQuitter(GtkWidget* widget, gpointer data);

// Fonction de destruction de la fenetre de demarrage
void Destruction_fenetre_demarrage( void );

//Fenetre qui affiche l'ecran de demarrage
void fenetre_ecran_demarrage( void );

void OnAbout(GtkWidget* widget, gpointer data);

void ajout_employe(void);

void manipulation(void);
void ajout_admin(void);

void ajout_seance(void);
void test_motpasse(void);
// Fenetre d'authentification
int Fenetre_Authentification( void );
    // Boîte de dialogue information
void message_info( GtkWindow *fparent, char *format, ... );

// Fenetre pour lister tous les employes
void fenetre_lister_employe( void );

        // Fenetre de confirmation d'une action
int fenetre_confirmation( char *message );


// Fenetre de changement de password
void Fenetre_Changer_Password( void );

// Creation et remplissage de la vue par les données
//GtkWidget* creation_vue_et_model( employe *liste, int nbre );

// Creation d'un modele de données pour un affichage des employes sous forme d'arbre
//GtkTreeModel* creation_et_remplissage_model ( employe *liste, int nbre );
//image de la fenetre principale
void f_image(void);
//initialiser toute les listes
void liste_null(void);

//fenetre de ajout de salle
//----------------------------------------------------------
void ajout_salle(void);

// Fonction d'ajout d'un employe a la liste
void ajouter_a_la_liste( GtkWidget *liste , employe *temp );


// Fonction d'initialisation de la liste des employes
void initialiser_liste( GtkWidget *liste );

void ouvrir_fichier(GtkWidget *pWidget, gpointer data);

void fenetre_modifier_seance( void );

//chargement des listes disponibles
void chargement_entiere();
// Fenetre de lecture des infos sur la seance
void  fenetre_lecture_info_seance( int mois,int jour,int  heure);

//fenetre film
void fenetre_ajout_film(void);

//fenetre lister seance
void  fenetre_lister_seance(void);

//lister employes
void  fenetre_lister_employe(void);

//lister administrateur
void  fenetre_lister_admin(void);


//lister salle
void  fenetre_lister_salle(void);

// Fenetre de suppression d'employe
void fenetre_supprimer_employe( void );

// Fenetre de suppression d'admin
void fenetre_supprimer_admin( void );

// Fenetre de suppression de seance
void fenetre_supprimer_seance( void );

//enregistement dans des fichiers
void enregistrement_entiere();

//supprimer une salle
void fenetre_supprimer_salle(void);

//lister film
void  fenetre_lister_film(void);

// Fenetre de suppression film
void fenetre_supprimer_film( void );

//lister film de la rechercher
void  fenetre_rechercher_lister_film(void);
//rechercher film
void  fenetre_rechercher_film(char *_titre );

//rechercher seance
void fenetre_rechercher_seance(char *mois,int jour);

//lister seance de la rechercher dans la journee
void  fenetre_rechercher_lister_seance(void);

//rechercher employe
void fenetre_rechercher_employe(char *_cin);


//lister employes rechercher
void  fenetre_lister_rechercher_employe(void);

//lister administrateur rechercher
void  fenetre_lister_rechercher_admin(void);

//rechercher administrateur
void fenetre_rechercher_admin(char *_cin);

 //fonction de test si la rechercher a abouti ou pas
 void test_admin(void);

    //fonction de test si la rechercher a abouti ou pas
 void test_employe(void);

    //fonction de test si la rechercher a abouti ou pas
 void test_employe1(void);

 //fonction de test si la liste est vide ou pas
 void test_admin1(void);

    //fonction de test si la rechercher a abouti ou pas
 void test_seance1(void);

   //fonction de test si la rechercher a abouti ou pas
 void test_seance(void);

   //fonction de test si la rechercher a abouti ou pas
 void test_film(void);

    //fonction de test si la rechercher a abouti ou pas
 void test_film1(void);

  //fonction de test si la rechercher a abouti ou pas
 void test_salle(void);
  //test de verification
 void test_ajout_seance(void);

 //fonction verifiant si la saisie sont des entier
int test_entier(char *data);



#endif
