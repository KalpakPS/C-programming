//sparse matrix addition
#include<stdio.h>
#define SIZE 5
void read();
void add();
void display();
int a[10][10],sa[20][3],b[10][10],sb[20][3],sc[20][3],i,j,k1,k2,m1,n1,m2,n2,k;
void read()
{
        printf("Enter the row and column of matrix 1\n");
        scanf("%d%d",&m1,&n1);
        printf("Enter the elements of matrix 1\n");
        for(i=0;i<m1;i++)
        {
            for(j=0;j<n1;j++)
                scanf("%d",&a[i][j]);
        }
        k1=1;
        for(i=0;i<m1;i++)
        {
            for(j=0;j<n1;j++)
            {
                if(a[i][j]!=0)
                {
                    sa[k1][0]=i;
                    sa[k1][1]=j;
                    sa[k1][2]=a[i][j];
                    k1++;
                }
            }
        }
        sa[0][0]=m1;sa[0][1]=n1;sa[0][2]=k1-1;
        printf("Enter the row and column of matrix 2\n");
        scanf("%d%d",&m2,&n2);
        printf("enter the elements of matrix 2\n");
        for(i=0;i<m2;i++)
        {
            for(j=0;j<n2;j++)
                scanf("%d",&b[i][j]);
        }
        k2=1;
        for(i=0;i<m2;i++)
        {
            for(j=0;j<n2;j++)
            {
                if(b[i][j]!=0)
                {
                    sb[k2][0]=i;
                    sb[k2][1]=j;
                    sb[k2][2]=b[i][j];
                    k2++;
                }
            }
        }
        sb[0][0]=m2;sb[0][1]=n2;sb[0][2]=k2-1;
 }
 void add()
{
    i=j=k=1;
    if((m1!=m2)&&(n1!=n2))
        printf("Addition is not possible\n");
    else
    {
        while((i<k1)&&(j<k2))
        {
            if(sa[i][0]<sb[j][0])
            {
                sc[k][0]=sa[i][0];
                sc[k][1]=sa[i][1];
                sc[k][2]=sa[i][2];
                i++;k++;
            }
            else if(sb[j][0]<sa[i][0])
            {
                sc[k][0]=sb[j][0];
                sc[k][1]=sb[j][1];
                sc[k][2]=sb[j][2];
                j++;k++;
            }
            else if(sa[i][0]==sb[j][0])
            {
                if(sa[i][1]<sb[j][1])
                {
                    sc[k][0]=sa[i][0];
                    sc[k][1]=sa[i][1];
                    sc[k][2]=sa[i][2];
                    i++;k++;
                }
                else if(sb[j][1]<sa[i][1])
                {
                    sc[k][0]=sb[j][0];
                    sc[k][1]=sb[j][1];
                    sc[k][2]=sb[j][2];
                    j++;k++;
                }
                else
                {
                    sc[k][0]=sa[i][0];
                    sc[k][1]=sa[i][1];
                    sc[k][2]=sa[i][2]+sb[j][2];
                    i++;j++;k++;
                }
            }
        }
        while(i<k1)
        {
            sc[k][0]=sa[i][0];
            sc[k][1]=sa[i][1];
            sc[k][2]=sa[i][2];
            i++;k++;
        }
        while(j<k2)
        {
            sc[k][0]=sb[j][0];
            sc[k][1]=sb[j][1];
            sc[k][2]=sb[j][2];
            j++;k++;
        }
        sc[0][0]=m1;
        sc[0][1]=n1;
        sc[0][2]=k-1;
    }
}
 void display()
 {
    printf("The matrix 1 is:\n");
    for(i=0;i<m1;i++)
    {
            for(j=0;j<n1;j++)
                printf("%4d\t",a[i][j]);
            printf("\n");
    }
    printf("The matrix 2 is:\n");
    for(i=0;i<m2;i++)
    {
            for(j=0;j<n2;j++)
                printf("%4d\t",b[i][j]);
                    printf("\n");
    }
    printf("The sparse matrix of 1 is:\n");
    for(i=0;i<k1;i++)
    {
            for(j=0;j<3;j++)
                printf("%4d\t",sa[i][j]);
                printf("\n");
    }
    printf("The sparse matrix of 2 is:\n");
    for(i=0;i<k2;i++)
    {
            for(j=0;j<3;j++)
                printf("%4d\t",sb[i][j]);
                printf("\n");
    }
    printf("The added sparse matrix is :\n");
    for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++)
            printf("%4d\t",sc[i][j]);
            printf("\n");
    }
 }
 void main()
{
    read();
    add();
    display();
}
