/**
 * file as3.c
 * date 27-02-2023
 * author Mohammad Deryl Ihzacky
 * NIM 2602181276
 * brief Tugas 3 - Double Linked List
**/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next, *prev;
} *head = NULL, *tail = NULL;

struct node *createNode(int num){

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp -> next = NULL;
    temp -> prev = NULL;
    temp -> data = num;

    return temp;
}

void pushHead(int num){

    struct node *temp = createNode(num);

    if(head == NULL){

        head = tail = temp;
        temp -> next = temp -> prev = NULL;  
    } else{
        
        head -> prev = temp;
        temp -> next = head;
        temp -> prev = NULL;
        head = temp;
    }
}

void pushTail(int num){

    struct node *temp = createNode(num);

    if(head == NULL){

        head = tail = temp;
        temp -> next = temp -> prev = NULL;  
    } else{
        
        tail -> next = temp;
        temp -> prev = tail;
        temp -> next = NULL;
        tail = temp;
    }
}

void popHead(){

    if (head == NULL){

        printf("No data\n");
        return;
    } else{
        
        head = head -> next;
        free(head -> prev);
        head -> prev = NULL;
    }
}

void popTail(){

    if (tail == NULL){

        printf("No data\n");
        return;
    } else{
        
        tail = tail -> prev;
        free(tail -> next);
        tail -> next = NULL;
    }
}

void printAll_next(){

    struct node *temp = head;
    printf("Print Next\n");
    while (temp != NULL){
        
        printf("%3d", temp -> data);
        temp = temp -> next;     
    }

    printf("\n");
}

void printAll_prev(){

    struct node *temp = tail;
    printf("Print Prev\n");
    while (temp != NULL){
        
        printf("%3d", temp -> data);
        temp = temp -> prev;     
    }

    printf("\n");
}

int main(){

    pushHead(2);
    pushTail(3);
    pushHead(5);
    pushTail(7);
    pushHead(9);
    pushTail(11);
    
    printAll_next();
    popHead();
    printAll_prev();
    popTail();
    printAll_prev();

    return 0;
}