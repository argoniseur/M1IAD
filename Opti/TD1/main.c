//
//  main.c
//  A13Machine
//
//  Created by Gabrielle Lopes on 14/05/2019.
//  Copyright © 2019 Gabrielle Lopes. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Element {
    int valeur;
    struct Element *suivant;
} Element;

typedef struct List {
    Element *elem;
}List;


// On mets la tête de liste à NULL
void Initialize(List * list){
    list->elem = NULL;
}


void Insert(List * list, Element element){
	Element *new = malloc(sizeof(Element));
    new->valeur = element.valeur;
    
    // Si le premier elem est NULL
    if(list->elem == NULL){
        list->elem = malloc(sizeof(Element));
        list->elem->valeur = element.valeur;
        list->elem->suivant = NULL;
        return;
    }
    
    // Si on doit insérer en tête
    if(list->elem->valeur > element.valeur){
		new->suivant = list->elem;
		list->elem = new;
		
		return;
	}
	
	// Si il y a qu'un elem dans la liste
	if(list->elem->suivant == NULL){
		list->elem->suivant = malloc(sizeof(Element));
		list->elem->suivant->valeur = element.valeur;
		list->elem->suivant->suivant = NULL;
		return;
	}
	
	// On parcours la liste 
    Element *current = list->elem->suivant;
    Element *previous = list->elem;
    while(current != NULL){
		if(element.valeur >= previous->valeur && element.valeur < current->valeur){
			new->suivant = current;
			previous->suivant = new;
			
			return;
		}
		
		previous = current;
		current = current->suivant;
	}
	
	// Si on a pas inséré on insère à la fin
	previous->suivant = new;
	new->suivant = NULL;
	
}

void Display(List list){
	Element *current = list.elem;
    
    // Parcours de liste
    while(current != NULL){
        printf("%d ", current->valeur);
        current = current->suivant;
    }
    printf("\n");
}

List Intersect(List list1, List list2){
	List *list = malloc(sizeof(List));
	Initialize(list);
	int tmp = INT_MIN;
	
	Element* current1 = list1.elem;
	Element* current2 = list2.elem;
	// Tant qu'un des deux n'est pas NULL
	while(current1 != NULL && current2 != NULL){
		// Si l'un est inférieur à l'autre, on l'incrémente et pas l'autre
		// Si les deux sont égaux et qu'on a pas déjà inséré ce chiffre, on l'insère et on incrémente les deux
		if(current1->valeur > current2->valeur){
			current2 = current2->suivant;
		}else if (current1->valeur < current2->valeur){
			current1 = current1->suivant;
		}else {
			if(tmp != current1->valeur){
				tmp = current1->valeur;
				Insert(list, *current1);
			}
			current2 = current2->suivant;
			current1 = current1->suivant;
		}
	}
	
	return *list;
}

List Union(List list1, List list2){
	List *list = malloc(sizeof(List));
	Initialize(list);
	int tmp = INT_MIN;
	
	Element* current1 = list1.elem;
	Element* current2 = list2.elem;
	while(current1 != NULL && current2 != NULL){
		// Si on a pas inséré la valeur dernièrement, on insère et on passe à l'autre
		if(current1->valeur > current2->valeur){
			if(tmp != current2->valeur){
				tmp = current2->valeur;
				Insert(list, *current2);
			}
			current2 = current2->suivant;
		}else if (current1->valeur < current2->valeur){
			if(tmp != current1->valeur){
				tmp = current1->valeur;
				Insert(list, *current1);
			}
			current1 = current1->suivant;
		}else {
			if(tmp != current1->valeur){
				tmp = current1->valeur;
				Insert(list, *current1);
			}
			current2 = current2->suivant;
			current1 = current1->suivant;
		}
	}
	// Quand un des deux atteint NULL, l'autre liste peut posséder encore des membres. Donc on les parcours pour les vider dans la liste retour
	if(current1 != NULL){
		while (current1 != NULL){
			if(tmp != current1->valeur){
				tmp = current1->valeur;
				Insert(list, *current1);
			}
			current1 = current1->suivant;
		}
	}else if (current2 != NULL){
		while(current2 != NULL){
			if(tmp != current2->valeur){
				tmp = current2->valeur;
				Insert(list, *current2);
			}
			current2 = current2->suivant;
		}
	}
	
	return *list;
}

int main(int argc, const char * argv[]) {
    List* list = malloc(sizeof(List));
    List* list2 = malloc(sizeof(List));
    Element *e = malloc(sizeof(Element));
    Element *i = malloc(sizeof(Element));
    Element *j = malloc(sizeof(Element));
    Element *k = malloc(sizeof(Element));
    e->valeur=7;
    i->valeur=6;
    j->valeur=8;
    k->valeur=9;
    
    Initialize(list);
    Initialize(list2);
    Insert(list, *e);
    Insert(list, *j);
    Insert(list, *i);
    Insert(list, *j);
    
    Insert(list2, *j);
    Insert(list2, *i);
    Insert(list2, *k);
    Insert(list2, *j);
    Display(*list);
    Display(*list2);
    
    Display(Intersect(*list, *list2));
    Display(Union(*list, *list2));
    return 0;
}


