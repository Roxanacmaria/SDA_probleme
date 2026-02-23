#include<stdio.h>
#include<stdlib.h>
struct NOD{
    char nume[255];
    struct NOD* next;
};
struct NOD* creare_nod(){
    struct NOD* nod_nou=NULL;
    nod_nou=(struct NOD*)malloc(sizeof(struct NOD));
    scanf("%s",nod_nou->nume);
    //nod_nou->carte=0;
    nod_nou->next=NULL;
    return nod_nou;
    
}
struct NOD* adauga_jucator(struct NOD* head)
{
    struct NOD* nod_curent=head,*nod_nou;
    if(head==NULL)
    {
        nod_nou=creare_nod();
        return nod_nou;
        
    }
    while(nod_curent->next!=NULL)
    {
       
        nod_curent=nod_curent->next;
    }
    nod_nou=creare_nod();
    nod_curent->next=nod_nou;
    return head;
}
void afisare(struct NOD* head)
{
    struct NOD* ptr=head;
    while(ptr!=NULL)
    {
        printf("%s\n",ptr->nume);
        ptr=ptr->next;
    }
}
int compara(int v[],int n)
{
    int min=v[0];
    int ind=0;
    for(int i=1;i<n;i++)
    {
        if(v[i]<min)
        {
          min=v[i];
          ind=i;
        }
    }
    return ind;
}
struct NOD* eliminare_jucator(struct NOD* head,int x,int n){
    struct NOD* nod_curent=head,*ptr_nod_sters;
    int ind=0;
     if (head == NULL) {
        //printf("Atentie: lista este goala.");
        
        return NULL;
    }
    if(head->next==NULL)
        {
            //printf("Avem un singur nod\n");
            free(head);
            //printf("Nodul a fost sters de la inceputul listei\n");
            return NULL;
            
        }
    if(x==0)
    {
      
           nod_curent=head;
           head=head->next;
           free(nod_curent);
           return head;
       
    }
    if(x==n-1)
    {
        while(nod_curent->next!=NULL)
        {
            if(nod_curent->next->next==NULL)
            {
                ptr_nod_sters=nod_curent->next;
                nod_curent->next=NULL;
                free(ptr_nod_sters);
                return head;
            }
            nod_curent=nod_curent->next;
        }
    }
    while(nod_curent!=NULL &&ind<x)
    {
        ptr_nod_sters=nod_curent;
            nod_curent=nod_curent->next;
            ind++;
        
    }
    
        if(nod_curent!=NULL)
        {
            ptr_nod_sters->next=nod_curent->next;
            free(nod_curent);
        }
    
    
    return head;
}
int main()
{
    struct NOD* lista_jucatori=NULL;
    int carti[255];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        lista_jucatori=adauga_jucator(lista_jucatori);
    }
   // afisare(lista_jucatori);
    int runda=n;
    while(n>0)
    {
        afisare(lista_jucatori);
       // printf("%d\n",n);
    
    //printf("%d\n",ind_st);
    for(int i=0;i<n;i++){
        scanf("%d",&carti[i]);
    }
    int ind_st=compara(carti,n);
    lista_jucatori=eliminare_jucator(lista_jucatori,ind_st, n);
    
    n--;
    // if(n>1)afisare(lista_jucatori);
    // else{
    //     printf("%s\n",lista_jucatori->nume);
    // }
    
    }
    free(lista_jucatori);
    return 0;
}