#include "employe.h"
#include"adminitration.h"
#include "seance1.h"


void menu()
{
     printf("\t                             GESTION\n");
     printf("\t*******************************************************************\n");
     printf("\t*         Taper E: GESTION DES EMPLOYES                           *\n\n");
     printf("\t*         Taper A: GESTION DE L ADMINISTRATION                    *\n\n");
     printf("\t*         Taper S: GESTION DES SEANCES                            *\n\n");
     printf("\t*         Taper ESC: QUITTER                                      *\n");
     printf("\t*******************************************************************\n");
}



//MENU D ACCEUIL

void menu_prin()
{
    printf("\t*******************************************************************\n");
    printf("\t*       BIENVENUE DANS L'APPLICATION DE GESTION                   *\n\n");
    printf("\t*                        CINEMA ENSIAS                            *\n");
    printf("\t*******************************************************************\n");
    printf("\n\n");
}
// FONCTION QUI ENGLOBE TOUTES LES AUTRES FONCTIONS QUE L'UTILISATEURS AURA AVOIR BESOIN:
void e_manipulation()
{
     char c;
     int N=1;
     char _cin[15];
     char _poste[20];
     e_init();
     e_chargement("employe");
     e_acceuil();
     e_menu();
     printf("\n\t\t\t            CHOISIR OPTION\n");
     do{
     printf("SELECT>> ");
     c = getch();
     printf("\n");
     switch(c)
     {
              case 'I':

                      system("cls");
                      printf("\t\t\t*********************\n");
                      printf("\t\t\t*   RECRUTEMENT     *\n");
                      printf("\t\t\t*********************\n\n");
                      e_saisie();
                      printf("*****************************************************************************\n");
                      break;

              case 'A' :system("cls");
                       e_afficher();
                       printf("******************************************************************************\n");
                       break;

              case 'C' :
                       system("cls");
                       printf("\t\t\t*********************\n");
                       printf("\t\t\t*     COMPTAGE      *\n");
                       printf("\t\t\t*********************\n");
                       printf("le nombre d'employe est %d\n",e_compter());
                       printf("******************************************************************************\n");
                       break;

              case 'h' :
                       system("cls");
                       printf("\t\t\t*********************\n");
                       printf("\t\t\t*     HISTORIQUE    *\n");
                       printf("\t\t\t*********************\n");
                       e_historique("e_historique");
                       printf("******************************************************************************\n");
                       break;
              case 'H' :
                        system("cls");
                       e_menu();
                       printf("******************************************************************************\n");
                       break;

              case 'R' :
                       system("cls");
                       printf("\t\t\t*********************\n");
                       printf("\t\t\t*     RECHERCHER    *\n");
                       printf("\t\t\t*********************\n");
                       fflush(stdin);
                       printf("Cin de l'employe :");
                       gets(_cin);
                       e_interm_rech(_cin);
                       printf("******************************************************************************\n");
                       break;

              case 'L' :
                       system("cls");
                       printf("\t\t\t*********************\n");
                       printf("\t\t\t*     LICENCIER     *\n");
                       printf("\t\t\t*********************\n");
                       printf("donner le numero_cin AAA :");
			           scanf("%s",_cin);
                       e_licencie(_cin);
                       printf("******************************************************************************\n");
                        break;
              case 'N' :
                        system("cls");
                        printf("\t\t\t*************************************\n");
                        printf("\t\t\t*     INFO SUR L ADMINISTRATION     *\n");
                        printf("\t\t\t*************************************\n");
                       // RENOUVELLER("administration",_poste);
                        printf("******************************************************************************\n");
                        break;

              case 27 :
                       system("cls");
                      // FIN();
                       N = 27;
                       break;

              default :
                        system("cls");
                      printf("\t\t\t TOUCHE INCORRECT \n\n");
     }
     }
     while(N != 27 );
     e_enregistrer("employe");
}



void a_manipulation()
{
     char c;
     int N=1;
     char _status[20];
     a_chargement("administration");
     system("cls");
     a_acceuil();
     a_menu();
     printf("\n\t\t\t            CHOISIR OPTION\n");
     do{
     printf("SELECT>> ");
     c = getch();
     printf("\n");
     switch(c)
     {
              case 'I':

                      system("cls");
                      printf("\t\t\t*********************\n");
                      printf("\t\t\t*   RECRUTEMENT     *\n");
                      printf("\t\t\t*********************\n\n");
                      a_saisie();
                      printf("*****************************************************************************\n");
                      break;

              case 'A' :system("cls");
                       a_afficher();
                       printf("******************************************************************************\n");
                       break;

              case 'C' :
                       system("cls");
                       printf("\t\t\t*********************\n");
                       printf("\t\t\t*     COMPTAGE      *\n");
                       printf("\t\t\t*********************\n");
                       printf("le nombre d'employe est %d\n",a_compter());
                       printf("******************************************************************************\n");
                       break;

              case 'h' :
                       system("cls");
                       printf("\t\t\t*********************\n");
                       printf("\t\t\t*     HISTORIQUE    *\n");
                       printf("\t\t\t*********************\n");
                      // a_historique("a_historique");
                       printf("******************************************************************************\n");
                       break;
              case 'H' :
                       system("cls");
                      //a_menu();
                       printf("******************************************************************************\n");
                       break;

              case 'R' :
                       system("cls");
                       printf("\t\t\t*********************\n");
                       printf("\t\t\t*     RECHERCHER    *\n");
                       printf("\t\t\t*********************\n");
                       printf("Status :");
                       gets(_status);
                       //a_rechercher(_status);
                       printf("******************************************************************************\n");
                       break;

              case 'L' :
                       system("cls");
                       printf("\t\t\t*********************\n");
                       printf("\t\t\t*     CHANGEMENT    *\n");
                       printf("\t\t\t*********************\n");
                       printf("donner le status :");
			           scanf("%s",_status);
                       a_licencie(_status);
                       printf("******************************************************************************\n");
                       break;
              case 'G' :
                        system("cls");
                        printf("\t\t\t*************************************\n");
                        printf("\t\t\t*    CHANGER MOT DE PASSE           *\n");
                        printf("\t\t\t*************************************\n");
                        changer("mot_passe.txt");
                         break;
              case 'N' :
                        system("cls");
                        printf("\t\t\t*************************************\n");
                        printf("\t\t\t*     INFO SUR L ADMINISTRATION     *\n");
                        printf("\t\t\t*************************************\n");
                       // a_renouveller("administration.txt",_status);
                        printf("******************************************************************************\n");
                        break;

              case 27 :
                       system("cls");
                       //FIN();
                       N = 27;
                       break;

              default :
                      system("cls");
                      printf("\t\t\t TOUCHE INCORRECT \n\n");
                      printf("\t\t\t VEUILLEZ TAPER SUR LA TOUCHE H POUR L AIDE\n");
     }
     }
     while(N != 27 );
     a_enregistrer("administration");
}


 //manipulation
void s_manipuler()
{
    char c;
    int N=1;
    s_init();
    chargement("seance.s");
    s_acceuil();
    s_menu();
    do
    {
        fflush(stdin);
    printf("SELECT>>");
    c = getch();
	  switch(c)
	  {
	    case 'A' :
		      system("cls");
		      afficher();
		      break;
	    case 'I' :
		      system("cls");
		      s_saisie();
		      break;
	    case 'R' :
		      system("cls");
		      rechercher();
		      break;
        case 'r' :
		      system("cls");
		      reporter();
		      break;
        case 'h' :
		      system("cls");
		      s_menu();
		      break;

	    case 27 :
		      system("cls");
		     // FIN();
		      N = 27;
		      break;
        default :system("cls");
        printf("\t\ttouche incorrect\n");
          }
    }while(N != 27);
     enregistrer("seance.s");
}


void globale_manipulation()
{
    char c;

    if(verifier("mot_passe") == 1)
    {


    do
    {
        menu_prin();
           menu();
    S1:printf("Select Gestion :");
    c = getch();
    switch(c)
    {
        case 'A' :
                system("cls");
                a_manipulation();
                break;
        case 'E' :
                system("cls");
                e_manipulation();
                break;

        case 'S' :
                system("cls");
                s_manipuler();
                break;
        case 27 :
                system("cls");
                FIN();

                break;
        default :
            system("cls");
             menu_prin();
             printf("\t\t\t touche incorrect\n\n");
            goto S1;
    }
    }while(c != 27);
    }
    else
     {
         FIN();
     }

}



