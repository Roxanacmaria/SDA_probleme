#include "functii.h"

/* functie creare a unui nod */
struct NOD * creare_nod(){
    struct NOD * nod;

    /* alocare memorie nod*/
    nod = (struct NOD * ) malloc(sizeof(struct NOD));

    if (nod == NULL) {
        printf("Eroare: memoria nu a putut fi alocata!\n");
        return NULL;
    }

    /* citire valori nod */
    printf("\nIntroduceti cuvant:");
    scanf("%s", nod -> cuvant);

    nod -> next = NULL;

    return nod;
}

/* functie populare lista cu n cuvinte */
struct NOD * populare_lista(struct NOD * head, int n){
    int i;
    for (i = 0; i < n; i++){
        head = adaugare_nod_sfarsit_lista(head);
    }
    return head;
}

/* functie afisare lista cuvinte */
void afisare_lista(struct NOD * head){
    int i = 0;
    struct NOD * nod_curent;

    if (head == NULL) {
        printf("Atentie, lista este goala!\n");
        return;
    }

    nod_curent = head;

    while (nod_curent != NULL) {
        /* afisare valoare curenta si pozitionare nod urmator */
        printf("%d: %s\n", i++, nod_curent -> cuvant);
        nod_curent = nod_curent -> next;
    }
}

/* functie adaugare cuvant la sfarsitul listei */
struct NOD * adaugare_nod_sfarsit_lista(struct NOD * head) {
    int i = 0;
    struct NOD * nod_curent, * nod_nou;

    if (head == NULL) {
        printf("Atentie: lista este goala.");
        head = creare_nod();
        printf("Cuvantul a fost adaugat.\n");
        return head;
    }

    /*parcurge lista element cu element pentru a ajunge la ultimul nod*/
    nod_curent = head;

    while (nod_curent != NULL) {
        if (nod_curent -> next == NULL) {
            /* creare si inserare nod nou in lista */
            nod_nou = creare_nod();
            nod_curent -> next = nod_nou;

            printf("Cuvantul a fost adaugat.\n");
            return head;
        }
        nod_curent = nod_curent -> next;
    }
}