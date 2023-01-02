#include<stdio.h>
struct student
{
   char name[20],add[30],dob[10]; 
}s[5];
void main()
{
    int i;
    printf("Enter the below details:\n");
    for(i=0;i<=5;i++)
    {   
        printf("Name:");
        gets(s[i].name);
        printf("Address:");
        gets(s[i].add);
        printf("DOB(dd/mm/yy):");
        gets(s[i].dob);
    }
    printf("The details of 5 students are:\n");
    for(i=0;i<=5;i++)
    {
        puts(s[i].name);
        puts(s[i].add);
        puts(s[i].dob);
        printf("\n");
        printf("*******************\n");
        printf("\n");
    }
}