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
#include <string.h>

#define SIZE 10	
#define INFINITE 10000

#define MAX_VAL 500

#define TAB_SIZE 10

int globalcounter = 0;


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
	Recuperer pere noeud pour dictionnaire.
*/

node_t* previous_node(node_t* z, ABR_t T)
{
	node_t* ptr = T;

	node_t* previous = NULL;

	while (ptr->val != z->val)
	{
		if (ptr->val < z->val)
		{
			previous = ptr;
			ptr = ptr->droite;
		}
		else if (ptr->val > z->val)
		{
			previous = ptr;
			ptr = ptr->gauche;
		}
	}

	return previous;
}

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

void parcoursABR_infixe(ABR_t T, int* tab) // dans l'ordre croissant, i.e. parcours infixe.
{
	if (T)
	{
		if (T->gauche)
		{
			parcoursABR_infixe(T->gauche, tab);
		}

		printf("%d -> ", T->val);
		tab[globalcounter] = T->val;
		globalcounter++;

		if (T->droite)
		{
			parcoursABR_infixe(T->droite, tab);
		}
	}
}


void parcoursABR_infixe_inverse(ABR_t T, int* tab) // dans l'ordre croissant, i.e. parcours infixe.
{
	if (T)
	{
		if (T->gauche)
		{
			parcoursABR_infixe_inverse(T->droite, tab);
		}

		printf("%d -> ", T->val);
		tab[globalcounter] = T->val;
		globalcounter++;

		if (T->droite)
		{
			parcoursABR_infixe_inverse(T->gauche, tab);
		}
	}
}




/*
	Fonction de recherche d'un noeud dans l'ABR.
*/

node_t* minABR(ABR_t T)
{
	node_t* ptr = T;

	while (ptr)
	{
		if (!ptr->gauche)
		{
			break;
		}

		ptr = ptr->gauche;
	}

	return ptr;
}

node_t* maxABR(ABR_t T)
{
	node_t* ptr = T;

	if (ptr != NULL)
	{
		while (ptr)
		{
			if (ptr->droite == NULL)
			{
				break;
			}

			ptr = ptr->droite;
		}
	}

	return ptr;
}


node_t* previousABR(node_t* x) //prédécesseur
{
	node_t* ptr = x;

	while (ptr)
	{
		if (!ptr->gauche)
		{
			break;
		}

		ptr = ptr->gauche;
	}

	return ptr;
}

node_t* nextABR(node_t* x) // successeur
{
	node_t* ptr = x;

	while (ptr)
	{
		if (!ptr->droite)
		{
			break;
		}

		ptr = ptr->droite;
	}

	return ptr;
}

node_t* search_in_ABR(int k, ABR_t T) // recherche d'un élément quelconque - récursif
{
	if (T->val == k)
	{
		node_t* val;
		val = T;
		return val;
	}
	else if (T->val > k)
	{
		search_in_ABR(k, T->gauche);
	}
	else
	{
		search_in_ABR(k, T->droite);
	}
}

node_t* search_in_ABR_it(int k, ABR_t T) // recherche d'un élément quelconque - itératif
{
	node_t* ptr = T;

	while (ptr->val != k)
	{
		if (ptr->val < k)
		{
			ptr = ptr->droite;
		}
		else if (ptr->val > k)
		{
			ptr = ptr->gauche;
		}
	}

	return ptr;
}


/*
	Création d'un dictionnaire
*/




/*
	Fonction de suppression d'un noeud dans l'ABR.
*/

ABR_t delete_in_ABR(node_t* z, ABR_t T)
{
	node_t* previous = NULL;

	node_t* direction = NULL;

	node_t* ptr = T;

	previous = previous_node(z, T);

	if (T == z) // Si tete de l'arbre.
	{
		direction = maxABR(z->gauche);

		ptr = previous_node(direction, T);

		direction->droite = z->droite;
		direction->gauche = z->gauche;

		ptr->droite = NULL;

		T = direction;
	}

	else if (previous->val < z->val) // si a droite de l'arbre.
	{
		if ((z->droite == NULL) && (z->gauche == NULL))
		{
			previous->droite = NULL;
		}
		else
		{
			previous->droite = z->gauche;
			direction = maxABR(z->gauche);
			direction->droite = z->droite;
		}
	}

	else // sinon a gauche de l'arbre.
	{
		if ((z->droite == NULL) && (z->gauche == NULL))
		{
			previous->gauche = NULL;
		}
		else
		{
			previous->gauche = z->droite;
			direction = minABR(z->droite);
			direction->gauche = z->gauche;
		}
	}

	free(z);

	return T;
}




/*
	Fonction de destruction d'un ABR.
*/

void delete_ABR(ABR_t T)
{
	while (T != NULL)
	{
		delete_in_ABR(T, T);
	}
}


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
	node_t* g = (node_t*)malloc(sizeof(node_t));
	node_t* h = (node_t*)malloc(sizeof(node_t));
	node_t* m = (node_t*)malloc(sizeof(node_t));
	node_t* n = (node_t*)malloc(sizeof(node_t));
	node_t* o = (node_t*)malloc(sizeof(node_t));
	node_t* p = (node_t*)malloc(sizeof(node_t));

	ABR_t T,T1;
	
	a->val = 10;
	b->val = 5;
	c->val = 15;
	d->val = 8;
	e->val = 12;
	f->val = 20;
	g->val = 11;
	h->val = 13;
	m->val = 21;
	n->val = 14;
	o->val = 6;
	p->val = 9;

	a->droite = c;
	a->gauche = b;

	b->droite = d;
	b->gauche = NULL;

	c->droite = f;
	c->gauche = e;

	d->droite = p;
	d->gauche = o;

	e->droite = h;
	e->gauche = g;

	f->droite = m;
	f->gauche = NULL;

	g->droite = NULL;
	g->gauche = NULL;

	h->droite = n;
	h->gauche = NULL;

	m->droite = NULL;
	m->gauche = NULL;

	n->droite = NULL;
	n->gauche = NULL;

	p->droite = NULL;
	p->gauche = NULL;

	o->droite = NULL;
	o->gauche = NULL;

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
	//T = insert_in_ABR(2, T);
	//T = insert_in_ABR(4, T);
	//T = insert_in_ABR(9, T);

	printf("\n INFIXE \n");
	afficheABR_infixe(T);

	printf("\n CREATE ARBRE \n");
	//T = create_nABR(10);
	afficheABR_infixe(T);

	printf("\n PARCOURS ARBRE \n");
	int* tab = (int*)malloc(TAB_SIZE * sizeof(int));
	globalcounter = 0;
	parcoursABR_infixe(T, tab);

	printf("\n MINIMUM ARBRE : %d \n", minABR(T)->val);
	printf("\n MAXIMUM ARBRE : %d \n", maxABR(T)->val);

	printf("\n PREVIOUS NODE : %d \n", previousABR(d)->val);
	printf("\n LAST     NODE : %d \n", nextABR(d)->val);

	printf("\n %d recherche \n", search_in_ABR(12, T)->val);
	printf("\n %d recherche_it \n", search_in_ABR_it(12, T)->val);

	T = delete_in_ABR(search_in_ABR_it(10, T), T);

	afficheABR_infixe(T);

	delete_ABR(T);

	afficheABR_infixe(T);

	printf("\n \n TERMINE \n");

	return 0;
}










