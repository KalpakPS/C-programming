#include<stdio.h>
void main()
{
    char str[20],revstr[20];
    int i,length=0;
    printf("Enter the string:");
    gets(str);
    for(i=0;str[i]!='\0';i++)
        length++;
    for(i=length-1;i>=0;i--)
        revstr[length-1-i]=str[i];
    puts(revstr);
}