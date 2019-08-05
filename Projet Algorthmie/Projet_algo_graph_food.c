#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIGNE 250
#define COLONNE 16 

// Definis une structure pour la matrice qui va servir à creer le graphe
typedef struct {

	int **mat;
	int taille;

} Graphe_matrice;

// Ecrire en dot pour generer le graphe
void CreerGraphe(Graphe_matrice *g, char** t){

	int i=0;

	FILE* fichier = NULL;
 
    fichier = fopen("grapheFood.txt", "w");
 
    if (fichier != NULL)
    {
    	fprintf(fichier, "digraph G {\n");
		for(i=0;i<g->taille;i++)
		{
			// on traite que la moitié du tableau car l'autre partie est identique
			for(j=0;j<g->taille-i;j++)
			{
			if(g->mat[i][j]==1)
			 fprintf(fichier, "%s -- %s", data[0][i],data[0][j]);
			}
		}
	   fprintf(fichier, "\n}");     
	        
	 fclose(fichier);
    }
 
}

// Initialise la matrice avec des 0
Graphe_matrice * initialisation()
{
	int i;
	Graphe_matrice * g;
	g = (Graphe_matrice *) malloc(sizeof(Graphe_matrice));
	g-> taille = COLONNE;
	g-> mat = (int**) malloc(sizeof(int*)*COLONNE);
	
	for(i=0;i<nbs;i++)
	{
		g-> mat[i]= (int *) calloc(LIGNE,sizeof(int));
	}
	return g;
}

// Insere une valeur dans la matrice selon a et b
void set_edge_matrice(Graphe_matrice *g, int a, int b, int val)
{
	g->mat[a][b]=val;
	g->mat[b][a]=val;
}

// Retourne le nombre d'arrete relié au sommet s
int degre_matrice(Graphe_matrice *g, int s)
{
	int i, d=0;
	for(i=0;i<g->taille;i++)
	{
		if(g->mat[s][i]!=0) d++;
	}
	return d;
}


// Insère la valeur 1 dans la matrice pour la colonne et la ligne correspondante
// Symbolise une arrete
int ajout_arrete(Graphe_matrice *g, int a, int b)
{
	set_edge_matrice(g,a,b,1);
}

// Insère la valeur 0 dans la matrice pour la colonne et la ligne correspondante
// Symbolise la suppression d'une arrete
int enleve_arrete(Graphe_matrice *g, int a, int b)
{
	set_edge_matrice(g,a,b,0);
}

// Ajoute une colonne au graphe
// Symbolise un sommet
int ajout_sommet(Graphe_matrice *g)
{
	g->taille++;
}

// Enleve une colonne au graphe
int enleve_sommet(Graphe_matrice *g)
{
	g->taille--;
}
//Affiche une representation du graphe
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

// Libere la memoire occupé par la matrice
int libere_matrice(int** tab, int taille){

	int i;
	
	for(i=0; i<taille; i++)
	{
	free(tab[i]);
	}
	free(tab);
}

// Alloue une taille pour le tableau dans la memoire 
void alloc_tab(char ** tab)

    tab =  (int**) malloc(sizeof(int*)*LIGNE);

    if(tab == NULL)
    {
        printf("Erreur d'allocation mémoire");
        return 0;
    }
 
    for(i = 0; i < LIGNE; i++)
    {
        tab[i] = (int *) calloc(LIGNE,sizeof(int))
 
        if(tab == NULL)
        {
            printf("Erreur d'allocation mémoire");
            return 0;
        }
    }

// Verifie si deux chaines sont identiques
bool compareChaine(char *s1, char *s2){
int i=0;
		while(s1[i]!=" "){
			if(s1[i]!=s2[i])
				return false;
		i++;
		}
return true;
}

//Affiche une representation du tableau
void affiche_tab(){

	
    for(i = 0; i < LIGNE; i++)
        printf("%d : %s\n",i, tab[i]);
}

// Libere la memoire occupé par le tableau
void libere_tab(){

	 
    for(i=0; i < LIGNE; i++)
        free(tab[i]);
 
    free(tab);
}



 
int main()
{
	// const char product_name[250][100];
 //    const char packaging_tags[250][50];
 //    const char brands_tags[250][50];
 //    const char main_category[250][50];
 //    const char second_category1[250][50];
 //    const char thirst_category2[250][50];
 //    const char categories_tags[250][500];
 //    const char manufacturing_places_tags[250][100];
 //    const char labels_tags[250][500];
 //    const char purchase_places[250][50];
 //    const char stores[250][50];
 //    const char countries_tags[250][50];
      const char ingredients_text[1024];
 //    const char traces_tags[250][500];
 //    const char additives_tags[250][100];
 //    const char groupe_tags[250][100];

   Graphe_matrice *g = initialisation();

   char str[1024];
   char *token,*line;
   int i=0,j=0;
   //char mat[1024][1024];
   char **data;
   int *p;

   alloc_tab(data);
   int nb_ligne=0;

   // Ouvre le fichier csv data_food
   FILE *fstream = fopen("data_food.csv","r");
   if(fstream == NULL)
   {
      printf("erreur d'ouverture du fichier ");
      return 0 ;
   }

   // Tant qu'il y'a des lignes non traité dans le tableau 
   // Recupere et stock la valeur
   while((line=fgets(str,sizeof(str),fstream))!=NULL)
   {
     token = strtok(line,";");
     while(token != NULL)
     {
     printf("token : %s",token) ;  
     data[j][i]=token;
     i++;
     }
     
     j++;
   }
  
  	// Affiche le tableau
	affiche_tab(data);

    	for(i=0;i<;i++){
    		if(data[12][i]=" ")
    			break;
    		else
    		{
    			strcpy(ingredients_text[i], data[12][i]);	
    		}
    		i++;
    	}
    	nb_ligne=i;



    	//Ajoute une arrete entre les sommets 
    	//si le nom d'un ingredient est présent entre deux recettes
    	for(j=0;j<nb_ligne;j++){
    		for(i=0;i<nb_ligne;i++){
    			token1 = strtok(mat[12][i]," ");
    			token2 = strtok(mat[12][j]," ");
    			 while(token != NULL && token2 != NULL)
     			{
     				if(compareChaine( token1 , token2) )
   						ajout_arrete(g,i,j); 
     			}
   			
   			}
   		}
	
	// affiche la matrice finalisé

	affichage_graphe_matrice(g);
	

	CreerGraphe(g->mat,data);

	//liberation de memoire 

	libere_tab(data);
	libere_matrice(g->mat,1024);


   return 0 ;
 }

 