/* *************************************************** */
/*  Linked List Definitions                            */
/*  Created by alexeal on 11/01/2014.                  */
/*  Copyright (c) 2014 alexeal. All rights reserved.   */
/* *************************************************** */

typedef struct element{
   struct element *next;
   void *data;
} Element;

typedef struct linkedlist{
	Element *currentItem;
} LinkedList;

void init(LinkedList* L);
void display(LinkedList liste);
void unshift(LinkedList *liste, int value);
void push(LinkedList *liste, int value);
void pop(void);
// TODO: int isEmpty();
