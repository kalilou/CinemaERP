#include "film.h"




void f_init()// initialiser la liste film
{
    f_liste = NULL;
}


/* Fonction permetttant d'ajouter un film dans la liste chainnee creer ˆ partir du chargement du fichiere FILMS */
void ajout_film(char *_titre,char *_mois,char *_real, char *_acteurP,char *_acteurS, char *_synopsis, char *_version,int _duree,int _annee,int _jour)
{
    film *nouveau = (film*)malloc(sizeof(film));
    strcpy(nouveau->d.titre,_titre);
	strcpy(nouveau->d.mois ,_mois);
	strcpy(nouveau->d.real,_real);
	strcpy(nouveau->d.acteurP,_acteurP);
	strcpy(nouveau->d.acteurS,_acteurS);
	strcpy(nouveau->d.synopsis,_synopsis);
	strcpy(nouveau->d.version,_version);
	nouveau->d.duree = _duree;
	nouveau->d.annee  = _annee;
	nouveau->d.jour  = _jour;
	nouveau->next = f_liste;
	f_liste = nouveau;
}


//rechercher un film deja enregistrer
int f_rechercher(film *tempon)
{
  film  *temp =(film *)malloc(sizeof(film));
  int test;
  if(f_liste == NULL)  test =  0;

  else
  {
    temp = f_liste;
    while(temp != NULL)
    {
      if( strcmp(temp->d.titre,tempon->d.titre) == 0 && strcmp(temp->d.real , tempon->d.real ) == 0)
      {
        test = 1;
        break;
      }
      else
	  temp = temp->next;
    }

  }
  return test ;
}


//rechercher un film dans le stock
int f_rechercher1( char *titre)
{
  film  *temp =(film *)malloc(sizeof(film));
  int test;
  if(f_liste == NULL)  test =  0;

  else
  {
    temp = f_liste;
    while(temp != NULL)
    {
      if( strcmp(temp->d.titre,titre) == 0)
      {
        test = 1;
        break;
      }
      else
	  temp = temp->next;
    }

  }
  return test ;
}


// FONCTION QUI COMPTE LE NOMBRE DE FILM
int f_compter()
{
      film *temp = (film *)malloc(sizeof(film));
      int nbre_film = 0;
       if(f_liste == NULL)  return 0;
		    else
		    {
                temp = f_liste;
                while(temp != NULL);
                {
                    nbre_film ++;
                    temp = temp->next;
                }
            }
     return nbre_film ;
}


//FONCTION DE RECHERCHER
int f_rechercher_1(char *_titre,char *_real,char *_version)
{
    film *temp = (film *)malloc(sizeof(film));
    int test;
    if(f_liste == NULL)  test =  0;
    else
    {
        temp = f_liste;
            while(temp != NULL)
			{
               if(strcmp(temp->d.titre ,_titre) == 0 && strcmp(temp->d.real,_real) == 0 && strcmp(temp->d.version,_version) == 0)
                 {
                    test = 1;
                    break;
                 }
                 else
                 temp = temp->next;
			}
    }
    return test;
}


// FONCTION PERMETTANT LA SUPPRESSION AU DEBUT DE LA LISTE
int  f_supprimer(char *_titre,char *_real,char *_version)
{
    film *temp = (film *)malloc(sizeof(film));
        film *temp0 = (film *)malloc(sizeof(film));
      int test;

      if(f_liste == NULL)  test = 0;

           else{

               if(strcmp(f_liste->d.titre ,_titre) == 0 && strcmp(f_liste->d.real,_real) == 0 && strcmp(f_liste->d.version,_version) == 0)
               {
                   temp = f_liste;
                   f_liste = temp->next;
                   test = 1;
                   free(temp);
               }

                else
                {
               temp = f_liste;
               temp0 = f_liste;
               while(temp->next != NULL)
			{
			     if(strcmp(temp->d.titre ,_titre) == 0 && strcmp(temp->d.real,_real) == 0 && strcmp(temp->d.version,_version) == 0)
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

//enregistremement
int f_enregistrer(char *_fichier)
{
  FILE *fichier = fopen(_fichier,"wb");
 film *temp = (film *)malloc(sizeof(film));
 int test;
  if(fichier == NULL) return 0;
  else
  {
    temp = f_liste;
    while(temp != NULL)
    {
      fwrite(&temp->d,sizeof(film ),1,fichier);
      temp = temp->next;
    }
    test = 1;
  }
  fclose(fichier);
  return test;
}


//chargement
int f_chargement(char *_fichier)
{
  FILE *fichier = fopen(_fichier,"rb");
 film *temp = (film *)malloc(sizeof(film));
  int test;
  if(fichier == NULL) test = -1;
  else
  {
    while(fread(&temp->d,sizeof(film),1,fichier)!=0)
    {
   ajout_film(temp->d.titre,temp->d.mois,temp->d.real,temp->d.acteurP,temp->d.acteurS,temp->d.synopsis,temp->d.version,temp->d.duree,temp->d.annee,temp->d.jour);
    }
    test = 1;
  }
  fclose(fichier);
  return test;
}
