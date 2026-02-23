#include<stdlib.h>
#include<stdio.h>
void citire(int n, int *A)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",(A+i*n+j));
        }
    }
}
void afisare(int *A,int n)
{
  for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",*(A+i*n+j));
        }
        printf("\n");
    }   
}
void interschimbare(int pr,int u,int *A,int n)
{
    
        for(int j=0;j<n;j++)
        {
            int aux=*(A+pr*n+j);
            *(A+pr*n+j)=*(A+u*n+j);
            *(A+u*n+j)=aux;
        }
    
     afisare(A,n);  
}
int main()
{
    int n,*M=NULL;
    int p,ul;
    scanf("%d",&n);
    scanf("%d ",&p);
    scanf("%d",&ul);
    M=malloc(n*n*sizeof(int));
    citire(n,M);
    interschimbare(p,ul,M,n);
    
}