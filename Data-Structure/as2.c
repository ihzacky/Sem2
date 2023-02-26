/**
 * file as2.c
 * date 25-02-2023
 * author Mohammad Deryl Ihzacky
 * NIM 2602181276
 * brief Tugas 2 - Polynomial Representation
**/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;    
    int pow;     
    struct node *link; 
} *head, *current, *tail;

void pushTail(int koef, int pangkat){

    current = (struct node*)malloc(sizeof(struct node));
    current -> coef = koef;
    current -> pow = pangkat;
    current -> link = NULL;

    if (!head){

        head = tail = current;        
    } else{
        
        tail -> link = current;
        tail = current;
    }
}    

void print_data(){

    struct node *temp = head;
    while (temp != NULL){

        printf("%dX^%d", temp -> coef, temp -> pow);
        temp = temp -> link;   

        if (temp != NULL) {
            printf(" + ");
        }     
    }
    
    printf("\n");
}

int main() {

    pushTail(6, 3);
    pushTail(9, 2);
    pushTail(1, 0);

    print_data();

    return 0;
}