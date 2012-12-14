#include "interface.h"
#include  "employe.h"
#include  "adminitration.h"
#include  "seance1.h"
#include  "mot_passe.h"
#include  "salle.h"
#include "film.h"
//#include  "utile.c"

  GtkWidget *fenetre;



// Fonction de destruction de la fenetre de demarrage
void Destruction_fenetre_demarrage( void )
{
    if ( timer )
    g_source_remove ( timer );
	gtk_main_quit();
}

//Fenetre qui affiche l'ecran de demarrage
void fenetre_ecran_demarrage( void )
{
    // Déclaration des variable
    GtkWidget *f_demarrage;
	GtkWidget *v_box;
	GtkWidget *image;

    // Creation de la fenetre de demarrage
	f_demarrage = gtk_window_new( GTK_WINDOW_POPUP );
	gtk_window_set_position( GTK_WINDOW( f_demarrage ), GTK_WIN_POS_CENTER );
	gtk_window_set_default_size( GTK_WINDOW( f_demarrage ), 200,200 );
	gtk_window_set_title( GTK_WINDOW( f_demarrage ), "ENSIAS CINEMA" );

    // Creation d'un conteneur
	v_box = gtk_vbox_new( FALSE, 0 );
	gtk_container_add( GTK_CONTAINER( f_demarrage ), v_box );

	// Chargement de l'image
	image = gtk_image_new_from_file( "00.png" );
	gtk_box_pack_start( GTK_BOX( v_box ), image, FALSE, FALSE, 5 );

    // Affichage de la fenetre
	gtk_widget_show_all( f_demarrage );

	// Initialisation du timer
    timer = g_timeout_add( 2500, ( GSourceFunc )Destruction_fenetre_demarrage, NULL );

    // Lancement de la boucle événementielle
	gtk_main();

	// Destruction de la fenetre
    gtk_widget_destroy( f_demarrage );

}



GtkWidget * menu(void)
{
    GtkWidget *pVBox;
    GtkWidget *pMenuBar;
    GtkWidget *pMenu;
    GtkWidget *pMenuItem;

    /* Creation de la GtkVBox */
    pVBox = gtk_vbox_new(FALSE, 0);
   // gtk_container_add(GTK_CONTAINER(fenetre), pVBox);


/**** Creation du menu ****/
/* ETAPE 1 */
pMenuBar = gtk_menu_bar_new();
/** Premier sousmenu**/




pMenu = gtk_menu_new();
pMenuItem = gtk_menu_item_new_with_label("changer mot de passe" );
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(Fenetre_Changer_Password),(GtkWidget*) fenetre);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("ouvrir");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(ouvrir_fichier), NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Quitter");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(OnQuitter), fenetre);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);

pMenuItem = gtk_menu_item_new_with_label("fichier");
gtk_menu_item_set_submenu(GTK_MENU_ITEM(pMenuItem), pMenu);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBar), pMenuItem);
/* ETAPE 2 */
pMenu = gtk_menu_new();
/* ETAPE 3 */
pMenuItem = gtk_menu_item_new_with_label("Nouveau");
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(ajout_employe),NULL);
pMenuItem = gtk_menu_item_new_with_label("Lister");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK( test_employe1),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Rechercher");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK( test_employe),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Supprimer");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(fenetre_supprimer_employe),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
/* ETAPE 4 */
pMenuItem = gtk_menu_item_new_with_label("Employe");
/* ETAPE 5 */
gtk_menu_item_set_submenu(GTK_MENU_ITEM(pMenuItem), pMenu);
/* ETAPE 6 */
gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBar), pMenuItem);
//---------------------------------------------------------------------------------------------------
pMenu = gtk_menu_new();
/* ETAPE 3 */
pMenuItem = gtk_menu_item_new_with_label("Nouveau");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(ajout_admin),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Lister");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(test_admin1),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Rechercher");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(test_admin),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Supprimer");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(fenetre_supprimer_admin),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Administration");
gtk_menu_item_set_submenu(GTK_MENU_ITEM(pMenuItem), pMenu);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBar), pMenuItem);
//--------------------------------------------------------------------------------------------------
pMenu = gtk_menu_new();
pMenuItem = gtk_menu_item_new_with_label("Nouveau");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(test_ajout_seance),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Lister");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(test_seance1), fenetre);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Rechercher");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(test_seance),fenetre);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Supprimer");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(fenetre_supprimer_seance),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Seance");
gtk_menu_item_set_submenu(GTK_MENU_ITEM(pMenuItem), pMenu);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBar), pMenuItem);

//-------------------------------------------------------------------------------------------------
pMenu = gtk_menu_new();
pMenuItem = gtk_menu_item_new_with_label("Nouveau");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(fenetre_ajout_film),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Lister");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(test_film1),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Rechercher");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(test_film),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Supprimer");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(fenetre_supprimer_film),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Film");
gtk_menu_item_set_submenu(GTK_MENU_ITEM(pMenuItem), pMenu);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBar), pMenuItem);
//---------------------------------------------------------------------------------------------------

pMenu = gtk_menu_new();
pMenuItem = gtk_menu_item_new_with_label("Nouveau");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(ajout_salle),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Lister");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(test_salle),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Supprimer");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(fenetre_supprimer_salle),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Salle");
gtk_menu_item_set_submenu(GTK_MENU_ITEM(pMenuItem), pMenu);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBar), pMenuItem);

pMenu = gtk_menu_new();
pMenuItem = gtk_menu_item_new_with_label("Auteur");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK( OnAbout),(GtkWidget *) fenetre);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Historique");
gtk_menu_item_set_submenu(GTK_MENU_ITEM(pMenuItem), pMenu);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBar), pMenuItem);


/* Ajout du menu a la fenetre */
gtk_box_pack_start(GTK_BOX(pVBox), pMenuBar, FALSE, FALSE, 0);
return pVBox;
}


void OnQuitter(GtkWidget* widget, gpointer data)
{
GtkWidget *pQuestion;
pQuestion = gtk_message_dialog_new(GTK_WINDOW(data),
GTK_DIALOG_MODAL,
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_YES_NO,
"Voulez vous vraiment\n"
"quitter le programme?");
switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
{
case GTK_RESPONSE_YES:
gtk_main_quit();
break;
case GTK_RESPONSE_NONE:
case GTK_RESPONSE_NO:
gtk_widget_destroy(pQuestion);
break;
}
}


void OnAbout(GtkWidget* widget, gpointer data)
{
GtkWidget *pAbout;
pAbout = gtk_message_dialog_new (GTK_WINDOW(data),
GTK_DIALOG_MODAL,
GTK_MESSAGE_INFO,
GTK_BUTTONS_OK,
"Realiser par\n"
"Diaby Kalilou\n"
"Congo faical Yannick Palingwende\n");
gtk_dialog_run(GTK_DIALOG(pAbout));
gtk_widget_destroy(pAbout);
}


