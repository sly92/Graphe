#include <stdio.h>
#include <stdlib.h>

typedef struct {

	int **mat;
	int taille;

} Graphe_matrice;

void CreerGraphe(Graphe_matrice *g){

	int i=0;

	FILE* fichier = NULL;
 
    fichier = fopen("grapheMatrice.txt", "w");
 
    if (fichier != NULL)
    {
    	fprintf(fichier, "digraph G {\n");
		for(i=0;i<g->taille;i++)
		{
			// on traite que la moitié du tableau car l'autre partie est identique
			for(j=0;j<g->taille-i;j++)
			{
			if(g->mat[i][j]==1)
			 fprintf(fichier, "%d -- %d",i,j);
			}
		}
	   fprintf(fichier, "\n}");     
	        
	 fclose(fichier);
    }
 
}

Graphe_matrice * initialisation(int nbs)
{
	int i;
	Graphe_matrice * g;
	g = (Graphe_matrice *) malloc(sizeof(Graphe_matrice));
	g-> taille = nbs;
	g-> mat = (int**) malloc(sizeof(int*)*nbs);
	
	for(i=0;i<nbs;i++)
	{
		g-> mat[i]= (int *) calloc(nbs,sizeof(int));
	}
	return g;
}

void set_edge_matrice(Graphe_matrice *g, int a, int b, int val)
{
	g->mat[a][b]=val;
	g->mat[b][a]=val;
}


int degre_matrice(Graphe_matrice *g, int s)
{
	int i, d=0;
	for(i=0;i<g->taille;i++)
	{
		if(g->mat[s][i]!=0) d++;
	}
	return d;
}

Graphe_matrice * creation_graphe_complet(int n)
{
	int i,j;
	Graphe_matrice *g;
	g= initialisation(n);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
				set_edge_matrice(g,i,j,1);
		}
	}
	return g;
}

int ajout_arrete(Graphe_matrice *g, int a, int b)
{
	set_edge_matrice(g,a,b,1);
}

int enleve_arrete(Graphe_matrice *g, int a, int b)
{
	set_edge_matrice(g,a,b,0);
}

void affichage_graphe_matrice(Graphe_matrice *g)
{
	int i,x,y;

	printf("\n Le graphe contient %d sommets",g->taille);
	printf("\n Matrice: ");
	printf("\n\t");
	
	for(i=0;i<g->taille;i++)
	{
		if(i<10)	printf(" [%d]",i);
		else		printf("[%d]",i);
	}
	printf("\n");
	
	for(y=0;y<g->taille;y++)
	{
		printf("\n[%d]\t",y);
	}	
	
	for(x=0;x<g->taille;x++)
	{
		printf(" %2d ",g->mat[x][y]);
	}
	printf("\t degre : %d",degre_matrice(g,y));
}

int ajout_sommet(Graphe_matrice *g)
{
	g->taille++;
}

int enleve_sommet(Graphe_matrice *g)
{
	g->taille--;
}

int libere_matrice(int** tab, int taille){

	int i;
	//On libere la memoire 
	for(i=0; i<taille; i++)
	{
	free(tab[i]);
	}
	free(tab);
}




int main(int argc, char const* argv[])
{
	int taille = 9;

	Graphe_matrice *g = initialisation(taille);

	affichage_graphe_matrice(g);

	libere_matrice(g->mat,g->taille);

	
	return 0;
}
