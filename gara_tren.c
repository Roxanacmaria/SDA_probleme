#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct STATIE{
  char *numeStatie;
  float coord_x;
  float coord_y;
};
struct RUTA{
  int nrStatii;
  struct STATIE *statii;
  float distantaTotala;
};
struct VAGON{
  int *hartaScaune;
  int randuriScaune;
  int coloaneScaune;
};
struct TREN{
  int idTren;
  int nrVagoane;
  struct VAGON *vagoane;
  struct RUTA *route;
};
struct GARA{
  char *nume;
  int nrTrenuri;
  struct TREN *trenuri;
};
struct CALATOR{
  char destinatie[255];
  int *trenuriDestinatie;
  int nrTrenuriDestinatieGasite;
};
char* citiresir()
{
    char *sir=NULL;
    char c;
    int lungime=0;
    sir=(char*)malloc(sizeof(char));
    while((c=getc(stdin))!='\n'&&c!=EOF)
    {
        
        sir[lungime]=c;
        lungime++;
        sir=(char*)realloc(sir,(lungime+1)*sizeof(char));
    }
    sir[lungime]='\0';
    return sir;
}
void harta(struct VAGON *v)
{
    v->hartaScaune=malloc(v->randuriScaune*v->coloaneScaune*sizeof(int));
    
    for(int i=0;i<v->randuriScaune;i++)
    {
        for(int j=0;j<v->coloaneScaune;j++)
        {
            *(v->hartaScaune+i*v->coloaneScaune+j)=rand()%2;
        }
    }
}
void afish(struct VAGON *v)
{
 for(int i=0;i<v->randuriScaune;i++)
    {
        for(int j=0;j<v->coloaneScaune;j++)
        {
            printf("%d",*(v->hartaScaune+i*v->coloaneScaune+j));
        }
        printf("\n");
    }   
}
float distanta()
int main()
{
  int t;
  struct GARA *gara=NULL;
  gara=(struct GARA *)malloc(sizeof(struct GARA ));
  gara->nume=NULL;
  gara->trenuri=NULL;
  scanf("%d",&t);
  getchar();
  srand((unsigned)time(NULL));
  switch(t){
      case 1:{
          gara->nume=citiresir();
          scanf("%d",&(gara->nrTrenuri));
          gara->trenuri=(struct TREN*)malloc(gara->nrTrenuri*sizeof(struct TREN));
          for(int i=0;i<gara->nrTrenuri;i++)
          {
              scanf("%d",&(gara->trenuri+i)->idTren);
              scanf("%d",&(gara->trenuri+i)->nrVagoane);
              (gara->trenuri+i)->vagoane=(struct VAGON*)malloc((gara->trenuri+i)->nrVagoane*sizeof(struct VAGON));
              for(int j=0;j<(gara->trenuri+i)->nrVagoane;j++)
              {
                  scanf("%d",&((gara->trenuri+i)->vagoane+j)->randuriScaune);
                  scanf("%d",&((gara->trenuri+i)->vagoane+j)->coloaneScaune);
                  harta((gara->trenuri+i)->vagoane+j);
              }
              (gara->trenuri+i)->route=(struct RUTA*)malloc(sizeof(struct RUTA));
              scanf("%d",&(gara->trenuri+i)->route->nrStatii);
              (gara->trenuri+i)->route->statii=(struct STATIE*)malloc((gara->trenuri+i)->route->nrStatii*sizeof(struct STATIE));
              getchar();
              for(int k=0;k<((gara->trenuri+i)->route->nrStatii);k++)
              {
                 ((gara->trenuri+i)->route->statii+k)->numeStatie=citiresir();
                 scanf("%f",&(((gara->trenuri+i)->route->statii+k)->coord_x));
                 scanf("%f",&(((gara->trenuri+i)->route->statii+k)->coord_y));
                 getchar();
              }
              (gara->trenuri+i)->route->distantaTotala=0;
              
          }
          
          break;
      }
      case 2:{
          printf("%s\n",gara->nume);
          printf("%d\n",gara->nrTrenuri);
           for(int i=0;i<gara->nrTrenuri;i++)
          {
              printf("%d\n",(gara->trenuri+i)->idTren);
              printf("%d\n",(gara->trenuri+i)->nrVagoane);
              for(int j=0;j<(gara->trenuri+i)->nrVagoane;j++)
              {
                  printf("%d\n",((gara->trenuri+i)->vagoane+j)->randuriScaune);
                  printf("%d\n",((gara->trenuri+i)->vagoane+j)->coloaneScaune);
                  afish((gara->trenuri+i)->vagoane+j);
              }
              printf("%d\n",(gara->trenuri+i)->route->nrStatii);
              for(int k=0;k<((gara->trenuri+i)->route->nrStatii);k++)
              {
                 printf("%s\n",((gara->trenuri+i)->route->statii+k)->numeStatie);
                 printf("%f\n",((gara->trenuri+i)->route->statii+k)->coord_x);
                 printf("%f\n",((gara->trenuri+i)->route->statii+k)->coord_y);
                 
              }
              printf("%d\n",(gara->trenuri+i)->route->distantaTotala);
          }
          break;
          
      }
      case 3:{
          struct CALATOR *calator=NULL;
          calator=(struct CALATOR *)malloc(sizeof(struct CALATOR ));
          calator->destinatie=citiresir();
          break;
      }
      default:
        break;
  }

    return 0;
}