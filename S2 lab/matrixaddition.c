//to add two matrix
#include<stdio.h>
void main()
{
    int a[10][10],b[10][10],c[10][10],i,j,m1,n1,m2,n2;
    printf("Enter the order of 1st matrix:\n");
    scanf("%d\t%d",&m1,&n1);
    printf("Enter the order of 2nd matrix:\n");
    scanf("%d\t%d",&m2,&n2);
    if(m1==m2&&n1==n2)
    {
        printf("Enter the elements of 1st matrix:\n");
        for(i=0;i<m1;i++)
            for(j=0;j<n1;j++)
                scanf("%d",&a[i][j]);
        printf("The inputted matrix is:\n");
        for(i=0;i<m1;i++)
        {
            for(j=0;j<n1;j++)
                printf("%4d",a[i][j]);
            printf("\n");
        }
        printf("Enter the elements of 2st matrix:\n");
        for(i=0;i<m2;i++)
            for(j=0;j<n2;j++)
                scanf("%d",&b[i][j]);
        printf("The inputted matrix is:\n");
        for(i=0;i<m2;i++)
        {
            for(j=0;j<n2;j++)
                printf("%4d",b[i][j]);
            printf("\n");
        }
        for(i=0;i<m1;i++)
            for(j=0;j<n1;j++)
                c[i][j]=a[i][j]+b[i][j];
        printf("The addition of these 2 matrix is:\n");
        for(i=0;i<m1;i++)
        {
            for(j=0;j<n1;j++)
                printf("%4d",c[i][j]);
            printf("\n");
        }
    }
    else
        printf("The order 2 matrises are not same so matrix addition cannot be performed\n");

    
}