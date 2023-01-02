#include<stdio.h>

void main()
{
    char revstr[20],str[20];
    int flag,length=0,i;
    printf("Enter the string:");
    gets(str);
    for(i=0;str[i]!='\0';i++)
    {
        length++;
    }
    printf("The length of %s= %d",str,length);
    printf("\n");
    for(i=length-1;i>=0;i--)
        revstr[length-i-1]=str[i];
    for(flag=1,i=0;i<length;i++)
    {
        if(revstr[i]!=str[i])
            flag=0;
    }
    if(flag==1)
        printf("The string %s is palindrome",str);
    else
        printf("The string %s is not palindrome",str);
}
