/* *************************************************** */
/*  Allocations                                        */
/*  Created by alexeal on 09/03/2014.                  */
/*  Copyright (c) 2014 alexeal. All rights reserved.   */
/* *************************************************** */

/* *************************************************** */
/*                       IMPORTS                       */
/*  stdio: standard input/output                       */
/*        used here for printf and scanf               */
/*  stdlib: standard library                           */
/*        used here for malloc and free                */
/*  string: standard lib for char manupulati           */
/*        used here for strlen and strcmp              */
/* *************************************************** */
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

/* *************************************************** */
/*                        GOAL                         */
/*  A list of person, with some actions possibles:     */
/*        Push, pop, delete and print details          */
/* *************************************************** */

typedef struct person
{
    char *name;
    char *address;
    struct person *next;
} Person;

typedef Person *People;

void init(People *lst) {
}

int push(People *lst, const char *name, const char *address) {
	Person *p = (Person *) malloc(sizeof(Person));
	if (p != NULL) {
		// Be careful not to forget NULL char at the end of the string (\0)
		// AZT: A Zero Terminal
		p->name = (char *) malloc((strlen(name) + 1) * sizeof(char));
        p->address = (char *) malloc((strlen(address) + 1) * sizeof(char));
        if (p->name != NULL && p->address != NULL) {
            strcpy(p->name, name);
            strcpy(p->address, address);
            p->next = *lst;
            *lst = p;
        } else {
            free(p);
            p = NULL;
        }
	}
	return (p != NULL);
}

int pop(People *lst, const char *name) {
	Person *prev = NULL;
    Person *p = *lst;
    while (p != NULL) {
        if (strcmp(p->name, name) == 0)
            break;
        prev = p;
        p = p->next;
    }
     if (p != NULL) {
     	// If prev == NULL -> It is the first element of the list
        if (prev == NULL) {
            *lst = p->next;
        } else {
            prev->next = p->next;
        }
        free(p->name);
        free(p->address);
        free(p);
    }
    return (p != NULL);
}

void print_list(People const *lst) {
	Person const *p = *lst;
    while (p != NULL) {
        printf("%s (%s)\n", p->name, p->address);
        p = p->next;
    }
}

void delete(People *lst) {
    while (*lst != NULL) {
        Person *p = *lst;
        *lst = p->next;
        free(p->name);
        free(p->address);
        free(p);
    }
    return ;
}

int main(int argc, const char * argv[]) {
	int option = 0;
	size_t stringLength;
    char buffer[16];
    char name[256];
    char address[256];
    People p;
    init(&p);
    
    do {
    	printf("0 = exit, 1 = push, 2 = pop, 3 = delete\n");
    	fgets(buffer, 16, stdin); // read input
        buffer[15] = 0; // to make sure to have \o char at the end
        option = 3;
        sscanf(buffer, "%d", &option); // sscanf extracts from buffer int value to put in option 
        switch(option) {
        	case 0:
        		break;
        	case 1:
        		printf("name:");
        		fgets(name, 256, stdin);
        		name[255] = 0;
        		stringLength = strlen(name);
        		if (name[stringLength - 1] == '\n') {
        			name[stringLength - 1] = 0; // remove \n
        		}
        		printf("address:");
        		fgets(address, 256, stdin);
        		address[255] = 0;
        		stringLength = strlen(address);
        		// remove \n
        		if (address[stringLength - 1] == '\n') {
        			address[stringLength - 1] = 0;
        		}
        		push(&p, name, address);
        		break;
        	case 2:
        		printf("name:");
        		fgets(name, 256, stdin);
        		name[255] = 0;
        		stringLength = strlen(name);
        		// remove \n
        		if (name[stringLength - 1] == '\n') {
        			name[stringLength - 1] = 0;
        		}
        		if (pop(&p, name) == 0) {
                	printf("Unknown person.\n");
            	}
        		break;
        	case 3:
        		delete(&p);
        		break;
        	default:
        		printf("%d is an unavailable option\n", option);
        		break;		
        }
        if (option != 0) print_list(&p);
    } while(option != 0);
	delete(&p); // delete allocations before leaving
	return 0;
}