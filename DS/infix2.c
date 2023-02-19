//infix to postfix
#include<stdio.h>
#include<string.h>
#include<math.h>
#include <ctype.h>
void convert();
void push(char);
char pop();
int isp(char);
int icp(char);
void evaluate();
void calc(int,int,char);
int top=-1,t=-1,s[20];
char infix[30],post[30],stack[30],x;
void main()
{
    printf("Enter an infix expression:");
    gets(infix);
    convert();
    printf("The postfix expression is:");
    puts(post);
    evaluate();
}
void convert()
{
    char item;
    int n=0,j=0,i=0,l;
    l=strlen(infix);
    push('(');
    while(n<l)
    {
        x=pop();
        item=infix[i];
        i++;
        if(isalpha(item))
        {
            push(x);
            post[j]=item;
            j++;
        }
        else
        {
            if(item==')')
            {
                while(x!='(')
                {
                    post[j]=x;
                    j++;
                    x=pop();
                }
            }
            else if(isp(x)>=icp(item))
            {
                while(isp(x)>=icp(item))
                {
                    post[j]=x;
                    j++;
                    x=pop();
                }
                push(x);
                push(item);
            }
            else if(isp(x)<icp(item))
            {
                push(x);
                push(item);
            }
            else
                printf("invalid entry\n");
        }
        n++;
        //puts(stack);
        //puts(post);
    }
    x=pop();
    while(x!='(')
    {
        post[j]=x;
        j++;
        x=pop();
    }
    post[j]='\0';
}
void push(char x)
{
    top++;
    stack[top]=x;
}
char pop()
{
    char a;
    a=stack[top];
    top--;
    return(a);
}
int isp(char x)
{
    switch(x)
    {
        case '+':return 2;
        case '-':return 2;
        case '*':return 4;
        case '/':return 4;
        case '^':return 5;
        case '(':return 0;
        case ')':return -1;
    }
    return (-1);
}
int icp(char x)
{
    switch(x)
    {
        case '+':return 1;
        case '-':return 1;
        case '*':return 3;
        case '/':return 3;
        case '^':return 6;
        case '(':return 9;
        case ')':return 0;
    }
    return (-1);
}
void evaluate()
{
    int m=0,n,n1,n2;
    char a;
    while(post[m]!='\0')
    {
        a=post[m];
        m++;
        if(isalpha(a))
        {
            printf("enter the value of %c ",a);
            scanf("%d",&n);
            s[++t]=n;
        }
        else
        {
            n1=s[t];
            t--;
            n2=s[t];
            t--;
            calc(n1,n2,a);
        }
    }
    printf("the result of the expression is %d",s[t]);
}
void calc(int n1,int n2,char a)
{
    int k;
    switch(a)
    {
        case '+':k=n1+n2;
            s[++t]=k;
            break;
        case '-':k=n2-n1;
            s[++t]=k;
            break;
        case '*':k=n1*n2;
            s[++t]=k;
            break;
        case '/':k=n2/n1;
            s[++t]=k;
            break;
        case '^':k=pow(n2,n1);
            s[++t]=k;
            break;
    }
}