#include"adminitration.h"

//initilisation de la liste
void a_initialiser()
{
    a_liste =NULL;
}
//DEFINITION DE LA FONCTION DE SAISIE DU STAFF ADMINISTRATION
void a_ajouter(char *_nom,char *_prenom,char *_adresse,char *_cin,char *_tel,char *_status)
{
    administration *nouveau = Malloc(administration);
    strcpy(nouveau->d.nom,_nom);
    strcpy(nouveau->d.prenom,_prenom);
    strcpy(nouveau->d.status,_status);
     strcpy(nouveau->d.adresse,_adresse);
     strcpy(nouveau->d.cin,_cin);
    strcpy(nouveau->d.tel,_tel);
    nouveau->next = a_liste;
    a_liste = nouveau;
}




//FONCTION DE RECHERCHER
int a_rechercher(char *_cin)
{
    administration *temp = Malloc(administration);
    if(a_liste == NULL) return 0;
    else
    {
        temp = a_liste;
            while(temp != NULL)
			{
               if(strcmp(temp->d.cin,_cin) == 0)
                 {
                     return 1;
                 }
                 else
                 temp = temp->next;
			}
    }
    return 0;
}

// FONCTION PERMETTANT LA SUPPRESSION ADMINISTRATION DE LA LISTE
void a_renouveller(char *_nom,char *_prenom,char *_status,char *_ancien_status)
{
            administration *temp;
                if(a_liste != NULL)
                {
                   temp = a_liste;
                   while(temp !=NULL)
                   {
                       if(strcmp(temp->d.status,_ancien_status)!=0)
                        {
                            strcpy(temp->d.nom,_nom);
                            strcpy(temp->d.prenom,_prenom);
                            strcpy(temp->d.status,_status);
                            break;
                        }
                        else temp =temp->next;
			        }
                }
                else printf("le cinema n'a pas d'aministrateur\n");


}


// FONCTION QUI COMPTE LE NOMBRE D EMPLOYE
int a_compter()
{
     FILE *fichier = fopen("administrateur","rb+");
      administration *temp;
      int nbre_admin = 0;
        if(fichier == NULL)   return 0;
        else{
        while(fread(&temp->d,sizeof(administration),1,fichier) != 0)
        {
         nbre_admin ++;
        }
     }
     fclose(fichier);
     return nbre_admin;
}

//enregistremement
void a_enregistrer(char *_fichier)
{
  FILE *fichier = fopen(_fichier,"wb");
  administration *temp;
  if(fichier == NULL)
  printf("ERREUR OUVERTURE DU FICHIER \n");
  else
  {
    temp = a_liste;
    while(temp != NULL)
    {
      fwrite(&temp->d,sizeof(administration),1,fichier);
      temp = temp->next;
    }
  }
  fclose(fichier);
}

//chargement
int a_chargement(char *_fichier)
{
  FILE *fichier = fopen(_fichier,"rb");
  administration *temp = Malloc(administration);
  int test;
  int i;
  if(fichier == NULL) test = -1;
    else
    {
    while(fread(&temp->d,sizeof(administration),1,fichier)!=0)
    {
      a_ajouter(temp->d.nom,temp->d.prenom,temp->d.adresse,temp->d.cin,temp->d.tel,temp->d.status);
    }
    test = 1;
    }
  fclose(fichier);
   return test;
}


// FONCTION PERMETTANT LA SUPPRESSION AU DEBUT DE LA LISTE
void a_licencie(char *_cin)
{
      administration *temp;
     administration *temp0;
      if(a_liste == NULL) printf("la liste est null\n");

           else{

               if(strcmp(a_liste->d.cin,_cin) == 0)
               {
                   temp = a_liste;
                   a_liste = temp->next;
                   free(temp);
               }

                else
                {
               temp = a_liste;
               temp0 = a_liste;
			while(temp->next =! NULL)
			{
				if(strcmp(temp->d.cin,_cin)!=0)
				{
				    temp0->next = temp->next;
				    free(temp);
				    break;
				}
				temp0 = temp;
				temp= temp->next;

			}
           }
           }
			if(temp == NULL) printf("Le cinema ne possede pas cet employe\n");

}
