#include<stdio.h>
#include<string.h>
void main()
{
    char str[30];
    int i,v,c;
    i=v=c=0;
    printf("Enter the string:");
    gets(str);
    strlwr(str);
    while(str[i]!='\0')
    {
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
            v++;
        else
            c++;
    i++;
    }
    printf("The number of vowels in string %s is %d\n",str,v);
    printf("The number of consonents in string %s is %d\n",str,c);

}