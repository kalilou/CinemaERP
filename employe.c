#include "employe.h"
#include "adminitration.h"
//initialiser la liste
void e_init()
{
    e_liste = NULL;
}
// FONCTION  POUR L'INSERTION
void e_ajouter(char *_nom,char *_prenom,char *_adresse,char *_cin,char *_tel,char *_status)
{
    	employe *nouveau = Malloc(employe);
        strcpy(nouveau->d.nom,_nom);
	    strcpy(nouveau->d.prenom,_prenom);
	    strcpy(nouveau->d.adresse,_adresse);
	    strcpy(nouveau->d.cin,_cin);
	    strcpy(nouveau->d.tel,_tel);
	    strcpy(nouveau->d.status,_status);
	    nouveau->next = e_liste;
	    e_liste = nouveau;
}

//chargement
int e_chargement(char *_fichier)
{
  FILE *fichier = fopen(_fichier,"rb");
  employe *temp = Malloc(employe);
  int test;
  if(fichier == NULL) test = -1;
  else
  {
    while(fread(&temp->d,sizeof(employe),1,fichier)!=0)
    {
     e_ajouter(temp->d.nom,temp->d.prenom,temp->d.adresse,temp->d.cin,temp->d.tel,temp->d.status);
    }
    test = 1;
  }
  fclose(fichier);
  return test;
}

// FONCTION PERMETTANT LA SUPPRESSION AU DEBUT DE LA LISTE
int  e_licencie(char *_cin)
{
      employe *temp = Malloc(employe);
      employe *temp0 = Malloc(employe);
      int test;

      if(e_liste == NULL)  test = 0;

           else{

               if(strcmp(e_liste->d.cin,_cin) == 0)
               {
                   temp = e_liste;
                   e_liste = temp->next;
                   test = 1;
                   free(temp);
               }

                else
                {
               temp = e_liste;
               temp0 = e_liste;
			while(temp->next != NULL)
			{
				if(strcmp(temp->d.cin,_cin) ==0)
				{
				    temp0->next = temp->next;
				    test = 1;
				    free(temp);
				    break;
				}
				temp0 = temp;
				temp= temp->next;

			}
           }
           }
 return test;

}




// FONCTION QUI COMPTE LE NOMBRE D EMPLOYE
// FONCTION QUI COMPTE LE NOMBRE DE FILM
int e_compter()
{
      employe *temp = (employe *)malloc(sizeof(employe));
      int nbre_employe = 0;
       if(e_liste == NULL)  return 0;
		    else
		    {
                temp = e_liste;
                while(temp != NULL);
                {
                    nbre_employe ++;
                    temp = temp->next;
                }
            }
     return nbre_employe ;
}


//FONCTION DE RECHERCHER
int e_rechercher(char *_cin)
{
    employe *temp = Malloc(employe);
    if(e_liste == NULL)  return  0;
    else
    {
        temp = e_liste;
            while(temp != NULL)
			{
               if(strcmp(temp->d.cin,_cin) == 0)
                 {
                    return 1;
                 }
                 temp = temp->next;
			}
    }
    return 0;
}


//enregistremement
void e_enregistrer(char *_fichier)
{
  FILE *fichier = fopen(_fichier,"wb");
  employe *temp;
  if(fichier == NULL)
  printf("ERREUR OUVERTURE DU FICHIER \n");
  else
  {
    temp = e_liste;
    while(temp != NULL)
    {
      fwrite(&temp->d,sizeof(employe),1,fichier);
      temp = temp->next;
    }
  }
  fclose(fichier);
}



// Fonction qui lit unemploye
/*employe* Lire_employe( char *Nom_Fichier, char  *cin )
{
    // Déclaration des variables locales
 employe *temp = Malloc(employe ) ;
    FILE *fd = fopen( Nom_Fichier, "rb" );

    // Vérifier que le fichier est bien ouvert
    if( fd == NULL )
        return NULL;

    // Parcours du fihier à la recherche du locataire
    while( fread( temp, sizeof( employe ), 1, fd ) != 0 )
        {
            if( strcmp(temp->d.cin, cin) == 0)
                    break;
        }

    // Fermeture du fichier
    fclose( fd );

    return temp;
}*/





