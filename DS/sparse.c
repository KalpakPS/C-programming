//sparse matrix addition
#include<stdio.h>
void main()
{
    int k1=1,k2=1,k=1,i,j,m1,n1,m2,n2,a[10][10],b[10][10],spa[10][3],spb[10][3],spc[20][3];
    printf("Enter the row & coloum no of matrix 1:");
    scanf("%d%d",&m1,&n1);
    printf("Enter the elements of matrix 1:");
    for(i=0;i<m1;i++)
        for(j=0;j<n1;j++)
            scanf("%d",&a[i][j]);
    printf("Enter the row & coloum no of matrix 2:");
    scanf("%d%d",&m2,&n2);
    printf("Enter the elements of matrix 2:");
    for(i=0;i<m2;i++)
        for(j=0;j<n2;j++)
            scanf("%d",&b[i][j]);
    //coverting matrix 1 to sparse
    for(i=0;i<m1;i++)
        for(j=0;j<n1;j++)
            if(a[i][j]!=0)
            {
                spa[k1][0]=i;
                spa[k1][1]=j;
                spa[k1][2]=a[i][j];
                k1++;
            }
    spa[0][0]=m1;spa[0][1]=n1;spa[0][2]=k1-1;
    //coverting matrix 2 to sparse
    for(i=0;i<m2;i++)
        for(j=0;j<n2;j++)
            if(b[i][j]!=0)
            {
                spb[k2][0]=i;
                spb[k2][1]=j;
                spb[k2][2]=b[i][j];
                k2++;
            }
    spb[0][0]=m2;spb[0][1]=n2;spb[0][2]=k2-1;
    //displaying sparse matrix
    printf("Sparse matrix 1:\n");
    for(i=0;i<k1;i++)
    {
        for(j=0;j<3;j++)
            printf("%d\t",spa[i][j]);
        printf("\n");        
    }
    printf("Sparse matrix 2:\n");
    for(i=0;i<k2;i++)
    {
        for(j=0;j<3;j++)
            printf("%d\t",spb[i][j]);
        printf("\n");        
    }
    //Addition
    i=j=k=1;
    if(spa[0][0]!=spb[0][0]&&spa[0][1]!=spb[0][1])
        printf("Addition not possible!\n");
    else
    {
        while(i<=k1&&j<=k2)
        {
            if(spa[i][0]<spb[j][0])
            {
                spc[k][0]=spa[i][0];
                spc[k][1]=spa[i][1];
                spc[k][2]=spa[i][2];
                k++;i++;
            }
            else if(spa[i][0]>spb[j][0])
            {
                spc[k][0]=spb[j][0];
                spc[k][1]=spb[j][1];
                spc[k][2]=spb[j][2];
                k++;j++;
            }
            else if(spa[i][0]==spb[j][0])
            {
                if(spa[i][1]<spb[j][1])
                {
                    spc[k][0]=spa[i][0];
                    spc[k][1]=spa[i][1];
                    spc[k][2]=spa[i][2];
                    k++;i++;
                }
                else if(spa[i][1]>spb[j][1])
                {
                    spc[k][0]=spb[j][0];
                    spc[k][1]=spb[j][1];
                    spc[k][2]=spb[j][2];
                    k++;j++;
                }
                else if(spa[i][1]==spb[j][1])
                {
                    spc[k][0]=spa[i][0];
                    spc[k][1]=spa[i][1];
                    spc[k][2]=spa[i][2]+spb[j][2];
                    i++;j++;k++;
                }
            }
        }
        while(i<k1)
        {
            spc[k][0]=spa[i][0];
            spc[k][1]=spa[i][1];
            spc[k][2]=spa[i][2];
            k++;i++;
        }
        while(j<k2)
        {
            spc[k][0]=spb[j][0];
            spc[k][1]=spb[j][1];
            spc[k][2]=spb[j][2];
            k++;j++;   
        }
        spc[0][0]=spa[0][0];spc[0][1]=spa[0][1];spc[0][2]=k-1;
    }
    //some logic error
    printf("Added sparse matrix:\n");
    for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++)
            printf("%d\t",spc[i][j]);
        printf("\n");        
    }
}