/* *************************************************** */
/*  Working with arrays and pointers                   */
/*  Created by alexeal on 09/16/2014.                  */
/*  Copyright (c) 2014 alexeal. All rights reserved.   */
/* *************************************************** */

#include <stdio.h>
#include <stdlib.h>

/* print array with a simple for loop */
void printArray(int arr[], int arrayLenght) {
    for (int i=0; i < arrayLenght; i++) {
        printf("arr[%d]=%d\n",i, arr[i]);
    }
}

/*
	print array, the pointer's way
	int arr[] will create a new var within the function scope
	int *arr will just get address to the given array in param.
*/
void printArrayThroughPointer(int *arr, int arrayLenght) {
    /* 
    	i++ to get index
        arr++ to get next item through the pointer
     */
    for (int i=0; i<arrayLenght;i++, arr++){
        printf("arr[%d]=%d\n",i, *arr);
    }
}

int main(int argc, const char * argv[]) {

    /* pointer 101 */
    int myInteger=4;
    int *myPointer1=&myInteger;
    printf("myInteger (myInteger's value): %d\n", myInteger);
    printf("&myInteger (myInteger's address): %p\n", &myInteger);
    printf("myPointer1: %p\n", myPointer1);
    printf("*myPointer1 (myPointer's value): %d\n", *myPointer1);
    printf("&myPointer1 (myPointer1's address): %p\n", &myPointer1);
    
    /* pointer of array */
    int arr[3];
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;
    int *arrPointer=&arr[0]; // alternative: int *arrPointer=tab; 
    printf("%d\n",*arrPointer); // print 1
    
    /*
        First observation:
        Assuming arr == &arr[0]: arr+1 == &arr[1]
        In general: arr[i] == *(pointer+i) <=> arr+i == &arr[i]  
        WARNING: You can't do arr++.
     
        If we do pointer=arr, we give the pointer the address of the value at arr[0].
        If we do pointer=arr+1, we give the pointer the address of the value at arr[0+1].
        If we do pointer=arr+i, we give the pointer the address of the value at arr[0+i].
        NOTE: arr is always &arr[0];
     
        Second observation:
        *pointer points to address &arr[0]
        *(pointer+i) points to the address &arr[i] (so the value arr[i] is found)
        pointer+i adds i to &arr[x] (pointer first points to &arr[x], not necessarily &arr[0])
     
        int *pointeur=&arr[0];
        pointer=pointer+1 => pointer=&arr[1];
        pointer=pointer+1 => pointer=&arr[1+1]; => pointer=&arr[2];
        pointer=pointer-1 => pointer=&arr[2-1]; => pointer=&arr[1];
     
    */
    int *ptr=arr;
    printf("%d\n", *ptr); // print 1
    ptr=arr+1;
    printf("%d\n", *ptr); // print 2
    ptr=arr;
    printf("%d\n", *ptr); // print 1
    ptr++;
    printf("%d\n", *ptr); // print 2
    // WARNING: we cannot do ptr=arr++; we cannot increment arr (lvalue)
    
    
    
    /* ****************************************************************************** */
    /*    We're going to display the elements of an array in different ways:          */
    /*        - case by case with incrementation (or decrementation)                  */
    /*        - pointer                                                               */
    /*        - for loop                                                              */
    /*        - basic function                                                        */
    /*        - function with a pointer                                               */
    /*    Reminder :                                                                  */
    /*        1) Classic way to initializing an array:                                */
    /*            int arr[3];                                                         */
    /*            arr[0]=1;                                                           */
    /*            arr[1]=2;                                                           */
    /*            arr[2]=3;                                                           */
    /*        2) An array starts at index 0.                                          */
    /* ****************************************************************************** */

    
    int arr3[3]={1,2,3}; // quick init
    
    /* **************************************************** */
    /*                   NO POINTER WAY                     */
    /* **************************************************** */

    int index=0;
    printf("arr3[%d]: %d\n", index, arr3[index]);
    index++; // as we want to display next item we increment index
    // alternatives: index=index+1; or index+=1;
    printf("arr3[%d]: %d\n", index, arr3[index]);
    index++;
    printf("arr3[%d]: %d\n", index, arr3[index]);
    index--; // as we want to display previous item we decrement
    // alternatives: index=index-1; or index-=1;
    printf("arr3[%d]: %d\n", index, arr3[index]);
    
    /* **************************************************** */
    /*                      POINTER WAY                     */
    /* **************************************************** */

    int *t=arr3;
    printf("arr3[0]: %d\n",arr3[0]);
    /* 
        t points to the first value of arr3: &arr3[0].
        as we want to move on to the next element of the array (&arr3[1];)
        we'll increment the pointer
    */
    t++;
    printf("arr3[1]: %d, *t: %d\n",arr3[1], *t);
    t++;
    printf("arr3[2]: %d, *t: %d\n",arr3[2], *t);
    /*
        now t points to the second value of arr: &arr[2]
        as we want to go to the previous element of arr (&arr[1])
        we simply need to decrement the pointer
    */
    t--;
    printf("arr3[1]: %d, *t: %d\n",arr3[1], *t);

    /* **************************************************** */
    /*           PRINT ARRAY WITH A BASIC FOR LOOP          */
    /* **************************************************** */

    printf("printing array with a basic for loop:\n");
    for (int i=0; i<3;i++){
        printf("arr[%d]=%d\n",i, arr[i]);
    }
    
    /* **************************************************** */
    /*           PRINT ARRAY WITH A BASIC FUNCTION          */
    /* **************************************************** */    
    printf("printing array with a basic function:\n");
    printArray(arr, 3);
    
    /* **************************************************** */
    /*      PRINT ARRAY WITH A FUNCTION WITH A POINTER      */
    /* **************************************************** */ 
     
 	printf("printing array with a function and a pointer as parameter:\n");
    printArrayThroughPointer(arr, 3);
    
    /* **************************************************** */
    /*           POINTERS AND POINTERS TO POI?TERS          */
    /* **************************************************** */

    int *p, *p2, **pp;
    p=&myInteger; // p points to myInteger' address
    /*
    	int *x -> x is a int pointer
    	&x -> x's address
    	(type)x -> type cast, convert x to integer
    	int *x = (int *) &y; -> x points to &y casted into a int pointer
    */
    p2=(int *)&p;
    pp=&p; // pp poiting to the address of p
    printf("\n");
    printf("myInteger (myInteger's value): %d\n", myInteger);
    printf("&myInterger (myInteger's address): %p\n", &myInteger);
    printf("\n");
    
    printf("*p (myInteger's value): %d\n", *p);
    printf("p (myInteger's's adress): %p\n", p);
    printf("&p (p's address): %p\n", &p);
    printf("\n");
    
    printf("*p2: %d\n", *p2); // deferencing get tricky...
    printf("p2 (p's address): %p\n", p2); // yet we have the correct address
    printf("&p2 (p2's address): %p\n", &p2);
    printf("\n");
    
    printf("here comme the pointer to pointe (**pp)\n");
    printf("*pp (p's value, which is myInteger's address): %p\n", *pp);
    printf("pp (p's address): %p\n", pp);
    printf("&pp (pp's address): %p\n", &pp);
    printf("\n");
    /* Pointer to pointer can be use for 2D arrays */
    
    
    return 0;
}

