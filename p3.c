#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m,n,*M=NULL,*N=NULL;
    scanf("%d %d", &m, &n);
    M=malloc(m*n*sizeof(int));
    N=malloc(m*n*sizeof(int));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
         scanf("%d ", M+i*n+j);
    }
     for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
         scanf("%d ", N+i*n+j);
    }
     
    for(int i=0;i<m;i++)
        {
         for(int j=0;j<n;j++)
          printf("%d\t ", *(M+i*n+j));
        }
    for(int i=0;i<m;i++)
        {
         for(int j=0;j<n;j++)
          printf("%d\t ", *(N+i*n+j));
        }
    for(int i=0;i<m;i++)
        {
         for(int j=0;j<n;j++)
          printf("%d\t ", *(M+i*n+j)-*(N+i*n+j));
        }
}