//sparse matrix addition
#include<stdio.h>
int a[10][10],sa[10][10],b[10][10],sb[10][10],sc[10][10],i,j,k=1,k1=1,k2=1,m,n,p,q;
void convert();
void sparseadd();
void main()
{
    printf("Enter the limit of matrix 1\n");
        scanf("%d%d",&m,&n);
    printf("Enter the elements\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
    }
    printf("Matrix 1 is\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
                printf("%4d",a[i][j]);
        printf("\n");
    }
    printf("Enter the limit of matrix 2\n");
        scanf("%d%d",&p,&q);
    printf("Enter the elements\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
                scanf("%d",&b[i][j]);
    }
    printf("Matrix 2 is\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
                printf("%4d",b[i][j]);
        printf("\n");
    }
    convert();
    sparseadd();
}
void convert()
{
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
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
    sa[0][0]=m;sa[0][1]=n;sa[0][2]=k1-1;
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
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
    sb[0][0]=p;sb[0][1]=q;sb[0][2]=k2-1;
    printf("Sparse matrix 1 is\n");
    for(i=0;i<k1;i++)
    {
        for(j=0;j<3;j++)
            printf("%4d",sa[i][j]);
        printf("\n");
    }
    printf("Sparse matrix 2 is\n");
    for(i=0;i<k2;i++)
    {
        for(j=0;j<3;j++)
            printf("%4d",sb[i][j]);
        printf("\n");
    }
}
void sparseadd()
{
    i=1,j=1,k=1;
    if((m==p)&&(n==q))
    {
        while(i<k1&&j<k2)
        {
        if(sa[i][0]<sb[j][0])
        {
            sc[k][0]=sa[i][0];
            sc[k][1]=sa[i][1];
            sc[k][2]=sa[i][2];
            k++;i++;
        }
        else if(sa[i][0]>sb[j][0])
        {
            sc[k][0]=sb[j][0];
            sc[k][1]=sb[j][1];
            sc[k][2]=sb[j][2];
            k++;j++;
        }
        else
        {
            if(sa[i][1]<sb[j][1])
            {
                sc[k][0]=sa[i][0];
                sc[k][1]=sa[i][1];
                sc[k][2]=sa[i][2];
                k++;i++;
            }
            else if(sa[i][1]>sb[j][1])
             {
                    sc[k][0]=sb[j][0];
                    sc[k][1]=sb[j][1];
                    sc[k][2]=sb[j][2];
                    k++;j++;
             }
            else
            {
                sc[k][0]=sa[i][0];
                sc[k][1]=sa[i][1];
                sc[k][2]=sa[i][2]+sb[j][2];
                k++;i++;j++;
            }
        }
        }
        while(i<k1)
        {
            sc[k][0]=sa[i][0];
            sc[k][1]=sa[i][1];
            sc[k][2]=sa[i][2];
            k++;i++; 
        }
        while(j<k2)
        {
            sc[k][0]=sb[j][0];
            sc[k][1]=sb[j][1];
            sc[k][2]=sb[j][2];
            k++;j++;
        }
    }
    sc[0][0]=m;sc[0][1]=n;sc[0][2]=k-1;
    printf(" added Sparse matrix is\n");
    for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++)
            printf("%4d",sc[i][j]);
        printf("\n");
    }
}