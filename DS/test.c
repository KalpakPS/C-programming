#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
void evaluate();
char pop();
void push(char);
void calc(int,int,char);
void convert();
int isp(char);
int icp(char);
int top=-1,t=-1,s[30];
char infix[30],post[30],stack[30],x;
void main()
{
    printf("Enter the infix expression:");
    gets(infix);
    convert();
    printf("The postfix is:");
    puts(post);
    //evaluate();
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
            else if(isp(x)<=icp(item))
            {
                push(x);
                push(item);
            }
            else
                printf("invalid entry\n");
        }
        n++;
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
    return a;
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
    return(-1);
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
    return(-1);
}
