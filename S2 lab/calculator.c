//To implement calculator in c
#include<stdio.h>
void main()
{
    int a,b;
    char opt;
    printf("'+'Addition\n'-'Subtraction\n'*'Multiplication\n'/'Division\n");
    printf("Choose your option:\n");
    scanf("%s",&opt);
    printf("Enter 2 numbers:\n");
    scanf("%d%d",&a,&b);
    switch (opt)
    {
        case '+':   printf("The sum of %d & %d is %d",a,b,a+b);
            break;
        case '-':   printf("The difference of %d & %d is %d",a,b,a-b);
            break;
        case '*':   printf("The product of %d & %d is %d",a,b,a*b);
            break;
        case '/':   printf("The quotient of %d & %d is %d",a,b,a/b);
            break;
        default:    printf("Invalid input\n");
            break;
    }
}