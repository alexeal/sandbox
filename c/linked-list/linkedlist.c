/* *************************************************** */
/*  Linked List Methods.                               */
/*  Created by alexeal on 11/01/2014.                  */
/*  Copyright (c) 2014 alexeal. All rights reserved.   */
/* *************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"
	
void init(LinkedList* L){
	(*L).currentItem = NULL;
}

void display(LinkedList liste){
	Element *e;
	e=liste.currentItem;
	while (e!=NULL){
		printf("%p\n",e->data);
		e=e->next;
	}
}

void unshift(LinkedList *liste, int value){
	Element *e;
	e=malloc(sizeof(*e));
	e->data=&value;
	e->next=liste->currentItem;
	liste->currentItem=e;
}

void push(LinkedList *liste, int value){
	Element *e;
	e=malloc(sizeof(*e));
	e->data=&value;
	e->next=NULL;
	liste->currentItem=e;
}
