/************************************

	Arbres binaires de recherche !
		
	implantation en C !

************************************/


/*
*	
*	
*	Le but est d' :
*	- implanter les fonctions et procédures utilitaires (création, suppression, affichage...);
*	- implanter les fonctions de recherche et de parcours;
*	- Ce code sert de base à l'implantation d'un dictionnaire !
*	
*	
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

#define SIZE 10	
#define INFINITE 10000

#define MAX_VAL 500


/*
	L'ABR est représenté par avec un noeud de fin.
*/
struct node
{
	unsigned int val;
	struct node *gauche;
	struct node *droite;

};

typedef struct node node_t;

typedef struct node * ABR_t;

/*
	Procédures d'affichage et parcours.
*/

void afficheNode(node_t n)
{
	printf("\n AFFICHE NODE : %d \n", n.val);

}

void afficheABR_infixe(ABR_t T) // dans l'ordre croissant, i.e. parcours infixe.
{
	if (T)
	{
		if (T->gauche)
		{
			afficheABR_infixe(T->gauche);
		}

		printf("%d -> ", T->val);

		if (T->droite)
		{
			afficheABR_infixe(T->droite);
		}
	}
}

void afficheABR_prefixe(ABR_t T) // dans l'ordre croissant, i.e. parcours infixe.
{
	if (T)
	{
		printf("%d -> ", T->val);

		if (T->gauche)
		{
			afficheABR_prefixe(T->gauche);
		}

		if (T->droite)
		{
			afficheABR_prefixe(T->droite);
		}
	}
}

void afficheABR_postfixe(ABR_t T) // dans l'ordre croissant, i.e. parcours infixe.
{
	if (T)
	{
		if (T->gauche)
		{
			afficheABR_postfixe(T->gauche);
		}

		if (T->droite)
		{
			afficheABR_postfixe(T->droite);
		}

		printf("%d -> ", T->val);
	}
}


void afficheABR_infixe_inverse(ABR_t T) // dans l'ordre croissant, i.e. parcours infixe.
{
	if (T)
	{
		if (T->droite)
		{
			afficheABR_infixe_inverse(T->droite);
		}

		printf("%d -> ", T->val);

		if (T->gauche)
		{
			afficheABR_infixe_inverse(T->gauche);
		}
	}
}


/*
	Procédure d'insertion d'un noeud dans l'ABR.
*/

ABR_t insert_in_ABR(int k, ABR_t T)
{
	if (T)
	{
		if (T->gauche && T->val >= k)
		{
			insert_in_ABR(k, T->gauche);
		}

		else if (T->droite && T->val < k)
		{
			insert_in_ABR(k, T->droite);
		}

		else if (!T->droite && T->val < k)
		{
			node_t* val = (node_t*)malloc(sizeof(node_t));
			val->val = k;
			val->droite = NULL;
			val->gauche = NULL;
			T->droite = val;
		}

		else
		{
			node_t* val = (node_t*)malloc(sizeof(node_t));
			val->val = k;
			val->droite = NULL;
			val->gauche = NULL;
			T->gauche = val;
		}
	}

	return T;
}


/*
	Fonction de création d'un ABR (vide).
*/
ABR_t create_ABR()
{
	ABR_t T;
	node_t* node = (node_t*)malloc(sizeof(node_t));

	node->val = 0;
	node->droite = NULL;
	node->gauche = NULL;

	T = node;

	return T;
}

/*
	Fonction de création d'un ABR de n éléments aléatoires.
*/
ABR_t create_nABR(int n)
{
	ABR_t T = create_ABR();
	T->val = rand() % 21;

	int i = 1;

	for (i; i < n; i++)
	{
		T = insert_in_ABR(rand() % 21, T);
	}

	return T;
}



/*
	procédure de parcours (remplissage d'un tableau}.
*/

///void parcoursABR_infixe(ABR_t T, int* tab) // dans l'ordre croissant, i.e. parcours infixe.


///void parcoursABR_infixe_inverse(ABR_t T, int* tab) // dans l'ordre croissant, i.e. parcours infixe.




/*
	Fonction de recherche d'un noeud dans l'ABR.
*/

///node_t * minABR(ABR_t T)



///node_t * maxABR(ABR_t T)


///node_t * previousABR(node_t * x) //prédécesseur



///node_t * nextABR(node_t * x) // successeur

///node_t * search_in_ABR(int k,ABR_t T) // recherche d'un élément quelconque - récursif

///node_t * search_in_ABR_it(int k,ABR_t T) // recherche d'un élément quelconque - récursif


/*
	Création d'un dictionnaire
*/




/*
	Fonction de suppression d'un noeud dans l'ABR.
*/

///ABR_t delete_in_ABR(node_t * z, ABR_t T)




/*
	Fonction de destruction d'un ABR.
*/

///void delete_ABR(ABR_t T)



/********************

		MAIN !!

********************/

int main(){

	srand(time(NULL));

	int i,j,k;

	node_t* a = (node_t*)malloc(sizeof(node_t));
	node_t* b = (node_t*)malloc(sizeof(node_t));
	node_t* c = (node_t*)malloc(sizeof(node_t));
	node_t* d = (node_t*)malloc(sizeof(node_t));
	node_t* e = (node_t*)malloc(sizeof(node_t));
	node_t* f = (node_t*)malloc(sizeof(node_t));

	ABR_t T,T1;
	
	a->val = 10;
	b->val = 5;
	c->val = 15;
	d->val = 8;
	e->val = 12;
	f->val = 20;

	a->droite = c;
	a->gauche = b;

	b->droite = d;
	b->gauche = NULL;

	c->droite = f;
	c->gauche = e;

	d->droite = NULL;
	d->gauche = NULL;

	e->droite = NULL;
	e->gauche = NULL;

	f->droite = NULL;
	f->gauche = NULL;

	T = a;

	printf("\n INFIXE \n");
	afficheABR_infixe(T);

	printf("\n PREFIXE \n");
	afficheABR_prefixe(T);

	printf("\n POSTFIXE \n");
	afficheABR_postfixe(T);

	printf("\n INVERSE AFFIXE \n");
	afficheABR_infixe_inverse(T);

	printf("\n AJOUT \n");
	T = insert_in_ABR(2, T);
	T = insert_in_ABR(4, T);
	T = insert_in_ABR(9, T);

	printf("\n INFIXE \n");
	afficheABR_infixe(T);

	printf("\n CREATE ARBRE \n");
	T = create_nABR(3);
	afficheABR_infixe(T);

	printf("\n \n TERMINE \n");

	return 0;
}










