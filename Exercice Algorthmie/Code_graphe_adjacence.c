#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Element **premier; 
    int taille;
};

void CreerGraphe(Liste *liste){

	int s=0;

	FILE* fichier = NULL;
 
    fichier = fopen("grapheListe.txt", "w");
 
    if (fichier != NULL)
    {
    	fprintf(fichier, "digraph G {\n");
		for(s=0;s<liste->taille;s++)
		{
			Element *actuel = liste[s]->premier;

    		while (actuel != NULL)
    		{
        		fprintf(fichier, "%d -- %d", s,actuel->nombre);
        		actuel = actuel->suivant;		
    		}
			{
			
			 
			}
		}
	   fprintf(fichier, "\n}");     
	        
	 fclose(fichier);
    }
 
}
Liste *initialisation(nbs)
{
    Liste *liste;
    liste = (Liste *) malloc(sizeof(liste));
    liste -> taille = nbs;
    liste -> premier = (Element **) malloc(sizeof(Element*)*nbs);
    
	for(i=0;i<nbs;i++)
	{
		liste-> premier[i]= (Element *) calloc(nbs,sizeof(int));
	}
    if (liste == NULL || element == NULL)
    {
        return 0;
    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste,int s, int nb)
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        return 0;
    }
    nouveau->nombre = nb;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste[s]->premier;
    liste[s]->premier = nouveau;
}


int degre_matrice(Liste *liste, int s)
{
	int d=0;

    Element *actuel = liste[s]->premier;

    while (actuel != NULL)
    {
        d++;
        actuel = actuel->suivant;
    }

	return d;
}

void suppression(Liste *liste, int s)
{
    if (liste == NULL)
    {
        return 0;
    }

    if (liste->premier != NULL)
    {
        Element *e = liste[s]->premier;
        liste[s]->premier = liste[s]->premier->suivant;
        free(e);
    }
}

void suppressionMilieu(Liste *liste, int s)
{
	int i=0;
    if (liste == NULL)
    {
        return 0;
    }


    if (liste->premier != NULL)
    {
        Element *aSupprimer = liste[s]->premier;
        for(i=0;i<liste->taille-s;i++)
        liste[s]->premier = liste[s]->premier->suivant;
        free(aSupprimer);
    }
}

int ajout_arrete(Liste *liste, int s, int nb)
{
	  insertion(maListe, s, nb);
}

int enleve_arrete(Liste *liste, int s)
{
	  suppression(maListe,s);
}

void afficherListe(Liste *liste)
{
	printf("\n Le graphe contient %d sommets",liste->taille);
	printf("\n Liste: ");
	printf("\n\t");

	int s=0;
    if (liste == NULL)
    {
        return 0;
    }

    for(s=0;s<liste->taille;s++){
    Element *actuel = liste[s]->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
        s++;
    }
	}
}

int ajout_sommet(Liste *liste)
{
	liste->taille++;
}

int enleve_sommet(Liste *liste)
{
	liste->taille--;
}

int libere_liste(Liste *liste, int taille){

	int i;
	//On libere la memoire 
	for(i=0; i<taille; i++)
	{
	free(liste[i]);
	}
	free(liste);
}


int main(int argc, char const* argv[])
{
	int taille=5;
    Liste *maListe = initialisation(taille);

    insertion(maListe,0, 0);
    insertion(maListe,0, 5);
    insertion(maListe,2, 5);
    insertion(maListe,5, 6);
    insertion(maListe,8, 4);
    suppression(maListe);

    afficherListe(maListe);

	libere_matrice(liste->premier,liste->taille);


    return 0;
}