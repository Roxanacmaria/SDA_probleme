#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NOD{
  char nume[255];
  struct NOD* next;
};
struct NOD* adauga(struct NOD* head,char c[])
{
    struct NOD* nou=(struct NOD*)malloc(sizeof(struct NOD));
    strcpy(nou->nume,c);
    nou->next=NULL;
    if(head==NULL) return nou;
    else{
        nou->next=head;
        head=nou;
        return head;
    }
}
struct NOD* elimina(struct NOD* head)
{
    if(head==NULL)return NULL;
   struct NOD* temp=head;
    head=head->next;
    free(temp);
    return head;
}
void afisare(struct NOD* head)
{
    printf("%s,",head->nume);
    head=head->next;
}
int main()
{
   struct NOD*stiva=NULL;
   char name[255];
   char c;
   while(scanf("%c",&c)==1)
   {
       if(c=='+')
       {
           scanf(" %[^\n]",name);
           stiva=adauga(stiva,name);
       }
       if(c=='-')
       {
           if(stiva!=NULL)
           {afisare(stiva);
           stiva=elimina(stiva);}
       }
   }
   return 0;
}