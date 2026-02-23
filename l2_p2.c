#include<stdlib.h>
#include<stdio.h>

struct Fisier{
  int secventa[10];
  char nume[20];
  float normalizata[10];
};
// int maxi(int s[10])
// {
//     int max;
//     for(int i=0;i<10;i++)
//     {
//         if(s[i]>s[i+1])
//         {
//         max=s[i];
//         }
        
//         else{ max=s[i+1];}
//     }
//     return max;
// }
// int mini(int s[10])
// {
//     int mini;
//     for(int i=0;i<10;i++)
//     {
//         if(s[i]>s[i+1])
//         {
//         mini=s[i+1];}
        
//         else{ mini=s[i];}
//     }
//     return mini;
// }
void sc(struct Fisier *f,int n)
{
    int mx=f->secventa[0],mi=f->secventa[0];
    for(int j=1;j<10;j++)
        {
            if(f->secventa[j]>mx) { mx=f->secventa[j];}
            if(f->secventa[j]<mi) { mi=f->secventa[j];}
        }
    for(int j=0;j<10;j++)
       { f->normalizata[j]=(float)(f->secventa[j]-mi)/(mx-mi);
            
       }
      

    
}
void afisare(struct Fisier *f,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%.2f ",(f+i)->normalizata[j]);
        }
        printf("\n");
    }
}
int main()
{
    struct Fisier *fis=NULL;
    int n;
    scanf("%d",&n);
    fis=(struct Fisier *)malloc(n*sizeof(struct Fisier));
    for(int i=0;i<n;i++)
    {
        scanf("%s",(fis+i)->nume);
        for(int j=0;j<10;j++)
         {
             scanf("%d",&(fis+i)->secventa[j]);
         }
         
    }
    for(int i=0;i<n;i++)
    {
        sc((fis+i),n);
    }
    afisare(fis,n);
}