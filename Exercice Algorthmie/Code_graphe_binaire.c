#include <stdio.h>
#include <stdlib.h>

typedef struct {

	int **tab;
	int taille;

} tableau_binaire;


void CreerGraphe(tableau_binaire *tb){

	int i=0;

	FILE* fichier = NULL;
 
    fichier = fopen("grapheBinaire.txt", "w");
 
    if (fichier != NULL)
    {
    	fprintf(fichier, "digraph G {\n");

		for(i=0;i<tb->taille;i++)
		{
			for(j=0;j<tb->taille;j++)
			{
			if() // NE PAS OUBLIER
			 fprintf(fichier, "%d -- %d",i,j);
			}
		}
	   fprintf(fichier, "\n}");     
	        
	 fclose(fichier);
    }
 
}

tableau_binaire * initialisation(int nbs)
{
	int i;
	tableau_binaire * tb;
	tb = (tableau_binaire *) malloc(sizeof(tableau_binaire));
	tb-> taille = nbs;
	tb-> tableau_binaire = (int**) malloc(sizeof(int*)*nbs);
	
	for(i=0;i<nbs;i++)
	{
		tb-> tableau_binaire[i] = (int *) calloc(nbs,sizeof(int));
	}
	return tb;
}

void set_edge_binaire(tableau_binaire *tb, int s, int a)
{
	for(i=0;i<a;i++)
	tb->tab[s] >> 1 ;
}


int degre (int val){

int somme = 0;

	while(val !=0)
	{

	Somme += val%2 ;
	val = val >> 1 ; 
	}

return somme ;

}

int ajout_arrete(tableau_binaire *tb, int a, int b)
{
	set_edge_binaire(tb,a,b,1);
}

int enleve_arrete(tableau_binaire *tb, int a, int b)
{
	set_edge_binaire(tb,a,b,0);
}

void affichage_tableau_binaire(tableau_binaire *tb)
{
	int i,x,y;

	printf("\n Le graphe contient %d sommets",tb->taille);
	printf("\n Tableau binaire: ");
	printf("\n\t");
	
	for(i=0;i<tb->taille;i++)
	{
		if(i<10)	printf(" [%d]",i);
		else		printf("[%d]",i);
	}
}



int ajout_sommet(tableau_binaire *tb)
{
	t->taille++;
}

int enleve_sommet(tableau_binaire *tb)
{
	t->taille--;
}

int libere_tableau(tableau_binaire *tb, int taille){

	int i;
	//On libere la memoire 
	for(i=0; i<taille; i++)
	{
	free(tb[i]);
	}
	free(tb);
}




int main(int argc, char const* argv[])
{
	int taille =9;
	tableau_binaire *tb = initialisation(taille);

	affichage_tableau_binaire(tb);

	libere_matrice(tb->tab,tb->taille);

	
	return 0;
}
