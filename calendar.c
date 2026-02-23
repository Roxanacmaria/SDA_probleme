#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct NOD{
    int data;
    char nume_eveniment[255];
    struct NOD* next;
};
struct NOD* creare_nod()
{
    struct NOD * nod;
    nod=(struct NOD *)malloc(sizeof(struct NOD));
    if(nod==NULL)
    {
        printf("Eroare: memoria nu a putut fi alocata!\n");
        return NULL;
    }
    //printf("Introduceti eveniment:\n");
    scanf("%s %d",nod->nume_eveniment,&nod->data);
    nod->next=NULL;
    return nod;
    
}

void afisare_lista(struct NOD * head)
{
    //int i=0;
    struct NOD* nod_curent;
    if (head == NULL) {
        //printf("Atentie, lista este goala!\n");
        return;
    }
    nod_curent=head;
    while(nod_curent!=NULL)
    {
      printf("%s %d\n",nod_curent->nume_eveniment,nod_curent->data);
      nod_curent=nod_curent->next;
    }
    
}
void cautare_titlu(struct NOD* head,char titlu[])
{
    struct NOD* nod_curent=head;
    while(nod_curent!=NULL)
    {
        if(strcmp(nod_curent->nume_eveniment,titlu)==0)
        {
            printf("%d\n",nod_curent->data);
        }
        nod_curent=nod_curent->next;
    }
}
void cauta_data(struct NOD* head,int d)
{
    struct NOD* nod_curent=head;
    while(nod_curent!=NULL)
    {
        if(nod_curent->data==d)
        {
            printf("%s\n",nod_curent->nume_eveniment);
        }
        nod_curent=nod_curent->next;
    }
}
struct NOD* adaugare_nod_sf_lista(struct NOD* head)
{
    struct NOD * nod_curent, * nod_nou;

    if (head == NULL) {
        //printf("Atentie: lista este goala.");
        head = creare_nod();
        //printf("Cuvantul a fost adaugat.\n");
        return head;
    }
    nod_curent=head;
    while(nod_curent->next!=NULL)
    {
        nod_curent=nod_curent->next;
    }
    nod_nou=creare_nod();
    nod_curent->next=nod_nou;
    return head;
}
struct NOD* afisare_ordonata(struct NOD*head)
{
    struct NOD *ptr=head,*copie;
    int n=0;
     if (head == NULL) {
        //printf("Atentie: lista este goala.");
        head = creare_nod();
        //printf("Cuvantul a fost adaugat.\n");
        return head;
    }
    while(ptr!=NULL)
    {n++;
    ptr=ptr->next;
    }
    ptr=head;
    struct NOD **vect=(struct NOD **)malloc(n*sizeof(struct NOD *));
   for(int i=0;i<n;i++)
   {
       vect[i]=ptr;
       ptr=ptr->next;
   }
   for(int i=0;i<n-1;i++)
   {
       for(int j=i+1;j<n;j++)
       {
           if(vect[i]->data>vect[j]->data)
           {
               copie=vect[i];
               vect[i]=vect[j];
               vect[j]=copie;
           }
       }
   }
   for(int i=0;i<n;i++)
   {
       printf("%s %d\n",vect[i]->nume_eveniment,vect[i]->data);
   }
   free(vect);
   return head;
}
int main()
{
    struct NOD* lista_evenimente=NULL;
    int operatie,data_t;
    char nume[255];
    while(1){
        //printf("\nIntroduceti cerinta:");
        scanf("%d", & operatie);
        switch(operatie){
            case 1:{
                lista_evenimente=adaugare_nod_sf_lista(lista_evenimente);
                break;}
            case 2: {
                scanf("%s",nume);
                cautare_titlu(lista_evenimente,nume);
                break;
            }
            case 3: {
                scanf("%d",&data_t);
                cauta_data(lista_evenimente,data_t);
                break;
            }
            case 5: {
                afisare_ordonata(lista_evenimente);
                
                break;
            }
            case 4:
                {afisare_lista(lista_evenimente);
                break;}
            case 6:
               { exit(0);
                }
            default: 
                break;
        }
    }
    return 0;
}