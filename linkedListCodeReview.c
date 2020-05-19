// http://hpca23.cse.tamu.edu/taco/utsa-www/ut/utsa/cs1723/lecture4.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------structs-----------------

typedef struct student {
	int	id;
	char name[100];
	float notaAluno;
} student;


// nó
typedef struct node {
	student	listaAlunos;
	struct node *next; // ponteiro para o próximo elemento
} node, *list;

//------------------------------------------


// Protótipos de funções
void insertList (list *L, student listaAlunos);
void createList (list *L);
student *searchList (list L, int id);

//------------------------------------------


int main () {
	list C;	/* a class of students */
	student	s, *p;
	int	id;
	FILE *f;

	f = fopen ("./list.txt", "r");
	if (!f) {
		perror ("List");
		exit (1);
	}

	createList (&C);

	for (;;) {
		fscanf (f, "%d %s %f\n", &s.id, s.name, &s.notaAluno);
		if (feof (f))
      break;
		insertList (&C, s);
	}
	fclose (f);

	for (;;) {
		printf ("Enter student ID, -1 to finish: ");
		scanf ("%d", &id);

		if (id == -1)
       break;

		p = searchList (C, id);


		if (!p)
			printf ("ID #%d not found!\n", id);
		else
			printf ("%d\t%s\t%0.2f\n", p -> id, p -> name, p -> notaAluno);
	}
	exit (0);
}

//--------------------------------------------------------



// ------------------------FUNÇÕES------------------------

void insertList (list *L, student listaAlunos) {
	node *p;
	p = (node *) malloc (sizeof (node));
	p -> listaAlunos = listaAlunos;
	p -> next = *L;
	*L = p;
}

/* make an empty list */

void createList (list *L) {
	*L = NULL;
}

student *searchList (list L, int id) {
	node *p;

	for (p = L; p && p -> listaAlunos.id != id; p = p -> next);

	if (p)
		return &p -> listaAlunos;
	else
		return NULL;
}