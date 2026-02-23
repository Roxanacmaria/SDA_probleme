#include<stdio.h>
#include<stdlib.h>
struct Foto{
  char name[10];  
  int *img;
  int appearance[16];
  
};
void afisare(struct Foto *f,int l,int c)
{
    // printf("%s",f->name);
    // printf("\n");
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",f->img[i*c+j]);
        }    printf("\n");
    }
     //printf("\n");
    //  for(int i=0;i<16;i++)
    //  {
    //      printf("%d ",f->appearance[i]);
    //  }
    //  printf("\n");
}
void af(struct Foto *f)
{
   for(int i=0;i<16;i++)
     {
         printf("%d ",f->appearance[i]);
     }
     printf("\n"); 
}
int main()
{
    int line,column,foto_number;
    struct Foto *pictures=NULL;
    scanf("%d",&foto_number);
    scanf("%d",&line);
    scanf("%d",&column);
    pictures=(struct Foto *)malloc(foto_number*sizeof(struct Foto));
    for(int i=0;i<foto_number;i++)
    {
        (pictures+i)->img=malloc(line*column*sizeof(int));
    }
    for(int i=0;i<foto_number;i++)
    {
        scanf("%s",&(pictures+i)->name);
        for(int j=0;j<line;j++)
        {
            for(int k=0;k<column;k++)
             {
                 scanf("%d",&(pictures+i)->img[j*column+k]);
             }
        }
    }
     for(int i=0;i<foto_number;i++)
    {
      for(int j=0;j<16;j++)
      {(pictures+i)->appearance[j]=0;}
    }
     for(int i=0;i<foto_number;i++)
    {
     for(int t=0;t<16;t++)
     {for(int j=0;j<line;j++)
        {
            for(int k=0;k<column;k++)
             {
                 if((pictures+i)->img[j*column+k]==t)
                 {
                     (pictures+i)->appearance[t]+=1;
                 }
             }
        } 
     }
    }
     for(int i=0;i<foto_number;i++)
    {
        afisare((pictures+i),line,column);
        //af((pictures+i));
    }
    for(int i=0;i<foto_number;i++)
    {
     af((pictures+i));
    }
    
    return 0;
}