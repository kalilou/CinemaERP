
#include "seance1.h"
//initialisation de la liste
void s_init()
{
  liste = NULL;
}

// saisir toute les seances de la semaine

void s_ajouter(char *_nom,char *_salle,char *mois ,int _jour , char *_version,int _heure,int _minute)
{
    seance *nouveau =(seance *)malloc(sizeof(seance));
    strcpy(nouveau->d.nom,_nom);
    strcpy(nouveau->d.salle,_salle);
       strcpy(nouveau->d.mois , mois);
       strcpy(nouveau->d.version,_version);
      nouveau->d.jour =_jour;
	 nouveau->d.heure = _heure;
	 nouveau->d.minute = _minute;
	 nouveau->next = liste;
	 liste = nouveau;
}

//rechercher une seance
int s_rechercher(seance *tempon)
{
  seance *temp =(seance *)malloc(sizeof(seance));
  int test;
  if(liste == NULL)  test =  0;

  else
  {
    temp = liste;
    while(temp != NULL)
    {
      if( strcmp(temp->d.mois , tempon->d.mois) == 0 && (temp->d.jour == tempon->d.jour) && (temp->d.heure == tempon->d.heure))
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


//rechercher une seance
int s_rechercher1(char *mois , int jour , int heure)
{
  seance *temp;
  int test ;
  if(liste == NULL) test = 0;

  else
  {
    temp = liste;
    while(temp != NULL)
    {
      if(strcmp(temp->d.mois , mois) == 0   && temp->d.jour == jour && temp->d.heure == heure)
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

//rechercher une seance
int s_rechercher2(char *mois , int jour )
{
  seance *temp;
  int test ;
  if(liste == NULL) test = 0;

  else
  {
    temp = liste;
    while(temp != NULL)
    {
      if(strcmp(temp->d.mois , mois) == 0   &&  temp->d.jour == jour)
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
//reporter une seance
seance * recuperer(char  *mois, int jour , int heure)
{
   seance *temp =(seance *)malloc(sizeof(seance));
   if(liste == NULL)  return  NULL ;
   else{
       temp = liste;
       while(temp != NULL)
       {
      if ( strcmp(temp->d.mois , mois) == 0  && temp->d.jour == jour &&   temp->d.heure==heure  )
	     break;
          else
	      temp = temp->next;
       }
    }
    return temp;
}
//enregistremement
int s_enregistrer(char *_fichier)
{
  FILE *fichier = fopen(_fichier,"wb");
  seance *temp =(seance *)malloc(sizeof(seance));
   int test;
  if(fichier == NULL)   test = 0;
  else
  {
    temp = liste;
    while(temp != NULL)
    {
      fwrite(&temp->d,sizeof(seance),1,fichier);
      temp = temp->next;
    }
    test = 1;
  }
  fclose(fichier);
  return test;
}
//chargement
int s_chargement(char *_fichier)
{
  FILE *fichier = fopen(_fichier,"rb");
  seance *temp =(seance *)malloc(sizeof(seance));
  int test;
  if(fichier == NULL)  test = -1;
  else
  {
    while(fread(&temp->d,sizeof(seance),1,fichier)  != 0 )
    {
     s_ajouter(temp->d.nom,temp->d.salle,temp->d.mois ,temp->d.jour,temp->d.version,temp->d.heure,temp->d.minute);
    }
    test = 1;
  }

  fclose(fichier);
  return test;
}



// Fonction qui modifie une seance
int modifier_seance( seance  *ancien , seance  *nouveau )
{

     seance *temp =(seance *)malloc(sizeof(seance));
    int test = 0;

    // Vérifie que le fichier est bien ouvert
    if( liste == NULL )
      test = -1;

        else{

    // Parcours du fichier de données
    temp = liste;
    while( temp != NULL )
        {
                if(temp->d.jour == ancien->d.jour && temp->d.heure == ancien->d.heure )
                    {
                            // Modification de la seance

                            supprimer_seance(ancien->d.mois,ancien->d.jour,ancien->d.heure);
                             s_ajouter(nouveau->d.nom,nouveau->d.salle,nouveau->d.mois,nouveau->d.jour,nouveau ->d.version,nouveau ->d.heure,nouveau->d.minute);
                             test = 1;
                            break;
                    }
                    else
                    temp = temp->next;
        }
        }

    return test;

}


int supprimer_seance( char *_mois, int _jour , int _heure)
{
        seance *temp =(seance *)malloc(sizeof(seance));
        seance *temp0 =(seance *)malloc(sizeof(seance));
      int test;

      if(liste == NULL)  test = 0;

 else{

               if( strcmp(liste->d.mois ,_mois) == 0   && liste->d.jour == _jour  &&  liste->d.heure == _heure)
               {
                   temp = liste;
                   liste = temp->next;
                   free(temp);
                   test = 1;
               }

                else
                {
               temp = liste;
               temp0 = liste;
                while(temp->next != NULL)
                {
                        if(strcmp(temp ->d.mois , _mois) ==0  && temp ->d.jour == _jour  &&  temp->d.heure == _heure)
                        {
                            temp0->next = temp->next;
                            free(temp);
                            test = 1;
                            break;
                        }
                        else
                        {
                        temp0 = temp;
                        temp= temp->next;
                        }

                }
           }
 }

           return test;

}





