#include <stdio.h>
#include<stdlib.h>
struct NOD{
  int id;
  struct NOD* next;
};
struct COADA{
    struct NOD* prim,*ultim;
};
struct COADA* mutare(struct COADA* head,struct COADA* vf)
{
    struct NOD* nou=malloc(sizeof(struct NOD));
    nou->id=vf->prim->id;
    nou->next=NULL;
 if(head->prim==NULL)   {
    head->prim=nou;
    head->ultim=head->prim;
 }
 else{
     head->ultim->next=nou;
     head->ultim=nou;
 }
 return head;
}
struct COADA* nerec(struct COADA*vf,int v)
{
    struct NOD*nou=malloc(sizeof(struct NOD));
    nou->id=v;
    nou->next=NULL;
    if(vf->prim==NULL)
    {
        vf->prim=nou;
        vf->ultim=vf->prim;
    }
    else{
        vf->ultim->next=nou;
        vf->ultim=nou;
    }
    return vf;
    
}
struct COADA* stergere(struct COADA* vf)
{
    struct NOD* temp=vf->prim;
    if(temp==NULL)return NULL;
    if(vf->ultim==vf->prim)
    {
        vf->prim=NULL;
        vf->ultim=NULL;
    }
    else vf->prim=vf->prim->next;
    free(temp);
    return vf;
}
void afisare(struct COADA* vf)
{
    if(vf==NULL)printf("\n");
    else{
        while(vf->prim)
        {printf("%d ",vf->prim->id);
        vf->prim=vf->prim->next;}
        printf("\n");
    }
}
int main()
{
   struct COADA *nerecep=NULL,*recep=NULL,*proces=NULL,*livr=NULL;
    nerecep=(struct COADA*)malloc(sizeof(struct COADA));
    recep=(struct COADA*)malloc(sizeof(struct COADA));
    livr=(struct COADA*)malloc(sizeof(struct COADA));
    proces=(struct COADA*)malloc(sizeof(struct COADA));
   
   int n;
   int *v=NULL;
   scanf("%d",&n);
   char c;
   v=malloc(n*sizeof(int));
   for(int i=0;i<n;i++)
   {
       scanf("%d",&v[i]);
       nerecep=nerec(nerecep,v[i]);
   }
   while(scanf("%c",&c)==1)
   {
       if(c=='r')
       {
           recep=mutare(recep,nerecep);
           nerecep=stergere(nerecep);
       }
       if(c=='p')
       {
           proces=mutare(proces,recep);
           recep=stergere(recep);
       }
       if(c=='l')
       {
           livr=mutare(livr,proces);
           proces=stergere(proces);
       }
   }
   afisare(nerecep);
    afisare(recep);
   afisare(proces);
  
   afisare(livr);
   
   
}