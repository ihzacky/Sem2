/**
 * file as1.c
 * date 23-02-2023
 * author Mohammad Deryl Ihzacky
 * NIM 2602181276
 * brief Tugas 1 - Structure
**/

#include <stdio.h>
#include <stdlib.h>

struct as2
{
    int student_num;
    int student_id;
    char student_name [100];
    float student_gpa;
} student[100];

void view_arr(int size){

    if (size == 0){
        
        printf("No data!\n\n");
    } else{

        for (int i = 0; i < size; i++){
            
            printf("Student No. %d\n", student[i].student_num); 
            printf("ID:\t%d\n", student[i].student_id); 
            printf("Name:\t%s\n", student[i].student_name); 
            printf("GPA:\t%.2f\n\n", student[i].student_gpa);

            printf("%d %s %.2f\n\n", student[i].student_id, student[i].student_name, student[i].student_gpa);
        }
    }
}

void insert_arr(int *size){

    student[*size].student_num = *size +1;

    printf("\nStudent No. %d\n", student[*size].student_num);

    printf("Student ID: ");
    scanf("%d", &student[*size].student_id); getchar();
    printf("Name: ");
    scanf("%[^\n]", &student[*size].student_name); getchar();
    printf("GPA: ");
    scanf("%f", &student[*size].student_gpa); getchar();
   
    *size = *size +1;
    system("cls");
}

int main(){

    system("cls");
    int cmnd = 0, size = 0;    
    do
    {
        
        printf("1. View\n2. Insert\n3. Exit\n>> ");
        scanf("%d", &cmnd); getchar();

        switch (cmnd)
        {
        case 1:
            system("cls");
            view_arr(size);
            break;
        case 2:
            system("cls");
            insert_arr(&size);
            break;
        default:
            break;
        }
        
    } while (cmnd != 3);
    
    return 0;
}