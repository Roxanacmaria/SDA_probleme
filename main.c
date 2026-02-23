#include "functii.h"

int main() {
    struct NOD * lista_cuvinte = NULL;
    int operatie, n = 0;
    char cuvant[20];

    printf("MENIU:\n");
    printf("[1] Popularea listei\n");
    printf("[2] Afisarea cuvintelor din lista\n");
    printf("[4] Adaugarea unui cuvant la finalul listei\n");
    printf("[10] Iesire din program\n");

    do {
        printf("\nIntroduceti operatie: ");
        scanf("%d", & operatie);
        
        switch(operatie){
            case 1:
                printf("\nPopularea listei\n");
                printf("\nIntroduceti numarul de cuvinte pe care doriti sa le introduceti in lista: ");
                scanf("%d", &n);
                if (n == 0)
                    printf("Eroare: numarul de cuvinte este 0");
                else {
                    lista_cuvinte = populare_lista(lista_cuvinte, n);
                }
                break;
            case 2:
                printf("\nAfisarea cuvintelor din lista\n");
                afisare_lista(lista_cuvinte);
                break;
            case 4:
                printf("\nAdaugarea unui cuvant la finalul listei\n");
                lista_cuvinte = adaugare_nod_sfarsit_lista(lista_cuvinte);
                break;
            case 10:
                printf("\nIesire din program\n");
                exit(0);
                break;
            default:
                printf("\nNumar invalid.\n");
                break;
        }
    } while (1);

    return 0;
}