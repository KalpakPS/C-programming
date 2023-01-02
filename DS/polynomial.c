//polynomial addition
#include<stdio.h>
struct poly
{
    int c,e;
}p1[20],p2[20],p3[40];
void main()
{
    int i,j,k,m,n,p;
    printf("Enter no of terms of p1:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter coef and exp of %d:",i+1);
        scanf("%d%d",&p1[i].c,&p1[i].e);
    }
    printf("Enter no of terms of p2:");
    scanf("%d",&m);
    for(j=0;j<m;j++)
    {
        printf("Enter coef and exp of %d:",j+1);
        scanf("%d%d",&p2[j].c,&p2[j].e);
    }
    //addition
    i=0,j=0,k=0;
    while(i<n&&j<m)
    {
        if(p1[i].e>p2[j].e)
        {
            p3[k]=p1[i];
            k++;i++;
        }
        else if(p2[j].e>p1[i].e)
        {
            p3[k]=p2[j];
            k++;j++;
        }
        else
        {
            p3[k].e=p1[i].e;
            p3[k].c=(p1[i].c+p2[j].c);
            i++;j++;k++;
        }
    }
    while(i<n)
    {
        p3[k]=p1[i];
        i++;k++;
    }
    while(j<m)
    {
        p3[k]=p2[j];
        j++;k++;
    }
    printf("Entered poly p1:\n");
    for(i=0;i<n-1;i++)
    {
        printf("%dx^%d+",p1[i].c,p1[i].e);
    }
    for(i=0;i<n;i++)
    {
        if(i==n-1)
        {
            if(p1[i].e!=0)
                printf("%dx^%d\n",p1[i].c,p1[i].e);
            else
                printf("%d\n",p1[i].c);
        }
    }
    printf("Entered poly p2:\n");
    for(j=0;j<m-1;j++)
    {
        printf("%dx^%d+",p2[j].c,p2[j].e);
    }
    for(j=0;j<m;j++)
    {
        if(j==m-1)
        {
            if(p2[j].e!=0)
                printf("%dx^%d\n",p2[j].c,p2[j].e);
            else
                printf("%d\n",p2[j].c);
        }
    }
    p=k;
    printf("After addition:\n");
    for(k=0;k<p-1;k++)
    {
        printf("%dx^%d+",p3[k].c,p3[k].e);
    }
    for(k=0;k<p;k++)
    {
        if(k==p-1)
        {
            if(p3[k].e!=0)
                printf("%dx^%d\n",p3[k].c,p3[k].e);
            else
                printf("%d\n",p3[k].c);
        }
    }     
}