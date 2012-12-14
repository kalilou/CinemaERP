#include "salle.h"


//initialisation de la liste salle
void init_salle()
{
    _liste = NULL;
}

//fonction d'ajout
void ajouter_salle(char *_salle,int _capacite)
{
    salle *nouveau = Malloc(salle);
    strcpy(nouveau->d.salle,_salle);
    nouveau->d.capacite = _capacite;
    nouveau->next = _liste;
    _liste = nouveau;
}
// fonction d'enrigistrement
int  enregistrer_salle(char *_fichier)
{
  FILE *fichier = fopen(_fichier,"wb");
  salle *temp = Malloc(salle);
  int test;
  if(fichier == NULL) test = -1;
  else
  {
    temp = _liste;
    while(temp != NULL)
    {
      fwrite(&temp->d,sizeof(salle),1,fichier);
      temp = temp->next;
    }
    test = 1;
  }
  fclose(fichier);
  return test;
}

//fonction  chargement
int chargement_salle(char *_fichier)
{
  FILE *fichier = fopen(_fichier,"rb");
  salle *temp = Malloc(salle);
  int test;
  if(fichier == NULL) test = -1;
  else
  {
    while(fread(&temp->d,sizeof(salle),1,fichier)!=0)
    {
     ajouter_salle(temp->d.salle,temp->d.capacite);
    }
    test = 1;
  }
  fclose(fichier);
}


// FONCTION PERMETTANT LA SUPPRESSION AU DEBUT DE LA LISTE
int supprimer_salle(char *_salle)
{
      salle *temp = (salle *)malloc(sizeof(salle));
      salle *temp0 = (salle *)malloc(sizeof(salle));
      int test;

      if(_liste == NULL)  test = 0;

           else{

               if(strcmp(_liste->d.salle,_salle) == 0)
               {
                   temp = _liste;
                   _liste = temp->next;
                   free(temp);
                   test =  1;
               }

                else
                {
               temp = _liste;
               temp0 = _liste;
			while(temp->next != NULL)
			{
				if(strcmp(temp->d.salle,_salle)!=0)
				{
				    temp0->next = temp->next;
				    free(temp);
				    test = 1;
				}
				temp0 = temp;
				temp= temp->next;

			}
           }
           }
           return test;

}


// FONCTION QUI COMPTE LE NOMBRE DE SALLE
int compter_salle()
{
      salle *temp =Malloc(salle);
      int nbre_employe = 0;
       if(_liste == NULL) nbre_employe = 0;
		    else
		    {
                temp = _liste;
                while(temp != NULL);
                {
                    nbre_employe ++;
                    temp = temp->next;
                }
            }
     return nbre_employe;
}


//FONCTION DE RECHERCHER
int rechercher_salle(char *_salle)
{
    salle *temp = Malloc(salle);
    if(_liste == NULL)  return 0;
    else
    {
        temp = _liste;
            while(temp != NULL)
			{
               if(strcmp(temp->d.salle,_salle) == 0)
                 {
                     return 1;
                 }
                 else
                 temp = temp->next;
			}
    }
}

