/* *************************************************** */
/*  Created by alexeal on 09/09/2014.                  */
/*  Copyright (c) 2014 alexeal. All rights reserved.   */
/* *************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int booleen;
#define TRUE 1
#define FALSE 0

float delta(double a, double b, double c) {
    return ((b*b)-(4*a*c));
}

void swap(int *value1, int *value2) {
    int tmp = *value1;
    *value1 = *value2;
    *value2 = tmp;
    printf("swap done ! \n");
}

int main(int argc, const char * argv[]) {
    /*  ************* */
    /*      TYPES     */
    /*  ************* */
    printf("types\n");
    int i = 1;
    unsigned u = 2;
    //long l = 3;
    float f = 4.0;
    double dd = 5.0;
    char cc = 97;
    unsigned char uc = -7;
    printf ("i = %d, u = %u,f = %f, dd = %lf, cc=%c, uc = %d\n",i,u,f,dd,cc,uc);
    printf ("print a tab with \'\\t\' and new line with \'\\n\'\n");
    
    /*  ******************************* */
    /*      ENUMS & TYPEDEF             */
    /*  ******************************* */
    printf("enums (and typedef)\n");
    enum week{LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE};
    enum week frenchDay=LUNDI;
    
    
    typedef enum days days;
    enum days{monday, tuesday, wednesday, thursday, friday, saturday, sunday};
    days englishDay=monday;
    
    printf("days enums: %d %d\n",frenchDay, englishDay);

    short NOTES[20]; // type short [20]
    typedef short NOTE[20]; // alias
    
    /*  ********************************* */
    /*      STRUCTS & TYPEDEF             */
    /*  ********************************* */
    printf("structs (and typedef)\n");
    struct Student{
        char *firstname;
        char *name;
        int age;
        double height;
    };
    /* one way to use typedef with struct */
    typedef struct Coordinates Coordinates;
    struct Coordinates{
        int x;
        int y;
    };
    
    /* another way to use typedef with struct */
    typedef struct Person{
        char *firstname;
        char *name;
        int age;
        double height;
    } Person;

    typedef struct Perso{
        char *firstname;
        char *name;
        int age;
        struct Perso *height; // /!\ not Perso *height
    } Perso;
    
    Person human;
    
    struct Student student;
    struct Student *studentPointer = &student;
    
    Coordinates myCoordinates;
    Coordinates *myCoordinatesPointer=&myCoordinates;
    
    student.firstname="John";
    student.name="Doe";
    student.age=21;
    student.height=1.67;
    printf("[Before modification through the pointer] %s %s, %d years old, %.2f m\n", student.firstname, student.name, student.age, student.height);
    
    studentPointer->firstname="Jean";
    studentPointer->name="Doeuf";
    printf("[After modification through the pointer] %s %s, %d years old, %.2f m\n", student.firstname, student.name, student.age, student.height);
    
    human.firstname="Jean";
    human.name="Dupont";
    human.age=35;
    human.height=1.70;
    printf("%s %s, %d years old, %.2f m\n", human.firstname, human.name, human.age, human.height);
    
    myCoordinates.x = 10;
    printf("[Before modification through the pointer] myCoordinates.x = %d\n", myCoordinates.x);
    
    myCoordinatesPointer->x = 11; // modificating x through the pointer
    printf("[After modification through the pointer] myCoordinates.x = %d\n", myCoordinates.x);
    
    printf("myCoordinatesPointer->x = %d\n", myCoordinatesPointer->x);
    
    /*  ***************************** */
    /*      ARRAYS & POINTERS.        */
    /*  ***************************** */
    printf("Arrays\n");
    
    /* 1D array */
    /* type name[nb_items] */
    int integerArray[10];
    /* init array */
    for (int i=0; i<10; i++) {
        integerArray[i]=0;
        printf("index: %d, ",i);
        printf("item: [%d]\n",integerArray[i]);
    }
    printf("\n");
    
    int *arrayPointer=integerArray; // alternative: int *arrayPointer=integerArray[0]
    // arrayPointer++ will point to the next item of the array
    for (int i=0; i<10; i++, arrayPointer++) {
        *arrayPointer=1;
        printf("index %d, ",i);
        printf("item: %d\n",*arrayPointer);
    }
    printf("\n");
    
    /* 2D array */
    /* type name[li][col] */
    char fullRectangle[4][4];
    char emptyRectangle[4][4];
    char triangle[3][5];
    
    for (int i=0; i<4;i++) {
        for (int j=0; j<4;j++) {
            fullRectangle[i][j]='*';
            printf("%c",fullRectangle[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    for (int i=0; i<4;i++) {
        for (int j=0; j<4;j++) {
            if (i==0 || i==3) {
                emptyRectangle[i][j]='*';
 
            } else {
                if(j<1 || j>2) {
                    emptyRectangle[i][j]='*';
                } else {
                    emptyRectangle[i][j]=' ';
                }
            }
            printf("%c",emptyRectangle[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    for (int i=0; i<3;i++) {
        for (int j=0; j<5;j++) {
            if ((i==0 && j==2)||(i==1 && (j>0 && j<4))|| i==2) {
                triangle[i][j]='*';
            } else{
                triangle[i][j]=' ';
            }     
            /* Decomposing triangle :
             if(i==0 && j==2) {
                triangle[i][j]='*';
             }else if(i==1 && (j>0 && j<4)) {
                triangle[i][j]='*';
             }else if(i==2) {
                triangle[i][j]='*';
             }else{
                triangle[i][j]=' ';
             }*/
            printf("%c",triangle[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    /*  *************************** */
    /*      POINTERS & MALLOC       */
    /*  *************************** */
    printf("pointers : \n");
    int myInteger = 10;
    int *ptr1 = &myInteger;
    int *ptr2 = ptr1; // ointing on &myInteger
    printf("integer : %d, pointer 1 : %d, pointer 2 : %d\n",myInteger, *ptr1, *ptr2);
    printf("%p, %p\n",ptr1, ptr2);
    printf("%p, %p\n",&ptr1, &ptr2);
    printf("swap\n");
    int value1=3, value2=10;
    printf("[Before swaping] value 1 : %d, value 2 : %d\n",value1, value2);
    swap(&value1, &value2);
    printf("[After swaping] value 1 : %d, value 2 : %d\n",value1, value2);
    
    /*  ******************************* */
    /*      QUADRATIC EQUATION          */
    /*  ******************************* */
    double a, b, c, result, d=0;
    printf("quadratic equation\n");
    printf("a : ");
    scanf("%lf", &a);
    printf("b : ");
    scanf("%lf", &b);
    printf("c : ");
    scanf("%lf", &c);
    d=delta(a, b, c);
    printf("delta: %.2f\n", d);
    b*=-1;
    if (d==0) {
        result = (b)/(2*a);
        printf("x0 = %.2f\n", result);
    } else if (d>0) {
        result = (b-sqrt(d))/(2*a);
        printf("x1 = %.2f\n", result);
        result = (b+sqrt(d))/(2*a);
        printf("x2 = %.2f\n", result);
    } else {
        printf("Negative set, find a solution with complex numbers\n");
        printf("First equation would be:\n%.2f-i*sqrt(%.2f)/2*%.2f\n", b,d,a);
        printf("Second one would be:\n%.2f+i*sqrt(%.2f)/2*%.2f\n", b,d,a);
    }
   
    return 0;
}