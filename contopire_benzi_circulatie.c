#include<stdio.h>
#include<stdlib.h>
struct NOD{
  char nr_inmatriculare[255];
  struct NOD *next;
};
struct NOD* creare_nod(){
    struct NOD*nod;
    nod=(struct NOD*)malloc(sizeof(struct NOD));
    if(nod==NULL)
    {
        printf("Alocare gresita\n");
        return NULL;
    }
    scanf("%s",nod->nr_inmatriculare);
    nod->next=NULL;
    return nod;
}
struct NOD*adauga(struct NOD*head,struct NOD*banda)
{
    struct NOD* nou=head;
    if(head==NULL)return banda;
    while(nou->next!=NULL)nou=nou->next;
    nou->next=banda;
    return head;
}
struct NOD* adauga_nod_sf(struct NOD* head)
{
    struct NOD* nod_curent=head,*nod_nou;
    
    if(head==NULL)
    {
        head=creare_nod();
        return head;
    }
    while(nod_curent!=NULL)
    {
        if(nod_curent->next==NULL)
        {
            nod_nou=creare_nod();
            nod_curent->next=nod_nou;
            return head;
        }
        nod_curent=nod_curent->next;
    }
}
void afisare(struct NOD* head){
    struct NOD* nod_curent;
    if(head==NULL)
    {
        printf("lista goala");
        return;
    }
    nod_curent=head;
    while(nod_curent!=NULL)
    {
        printf("%s\n",nod_curent->nr_inmatriculare);
        nod_curent=nod_curent->next;
    }
}
int main()
{
    struct NOD* lista=NULL,*banda1=NULL,*banda2=NULL;
    int n,m;
    scanf("%d",&m);
    scanf("%d",&n);
    for(int i=0;i<m;i++){
        banda1=adauga_nod_sf(banda1);
        
    }
    for(int i=0;i<n;i++){
        banda2=adauga_nod_sf(banda2);
        
    }
    while(banda2!=NULL || banda1!=NULL)
    {
        if(banda2!=NULL)
        {
            struct NOD*copy=banda2;
            banda2=banda2->next;
            copy->next=NULL;
            lista=adauga(lista,copy);
            
        }
        if(banda1!=NULL)
        {
            struct NOD*copy=banda1;
            banda1=banda1->next;
            copy->next=NULL;
            lista=adauga(lista,copy);
            
        }
    }
    afisare(lista);
    return 0;
    
}