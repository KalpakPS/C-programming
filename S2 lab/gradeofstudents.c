//the grade of students
#include<stdio.h>
void main()
{
    int m1,m2,m3,total;
    float p;
    char name[15];
    printf("Enter the name of the student:\n");
    scanf("%s",name);
    printf("Enter the marks of 3 subjects:\n");
    scanf("%d%d%d",&m1,&m2,&m3);
    total=m1+m2+m3;
    p=(total/300.0)*100;
    printf("Total=%d\nPercentage=%.2f\n",total,p);
    if(p>=90)
        printf("The grade is A+\n");
    else if(p>=80&&p<90)
        printf("The grade is A\n");
    else if(p>=70&&p<80)
        printf("The grade is B+\n");
    else if(p>=60&&p<70)
        printf("The grade is B\n");
    else if(p>=50&&p<60)
        printf("The grade is C\n");
    else if(p>=40&&p<50)
        printf("The grade is D");
    else
        printf("The student failed\n");
}