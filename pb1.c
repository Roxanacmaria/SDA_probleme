#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char a,b,*pa=NULL,*pb=NULL;
    int i=0,j=0;
    pa=malloc(sizeof(char));
    pb=malloc(sizeof(char));
    while((a=getc(stdin))!='\n')
    {
        
        
        pa=realloc(pa,(i+2));
       pa[i++]=a;
      //printf("%s", pa);  
        
    }
    pa[i] = '\0';
    while((b=getc(stdin))!='\n')
    {
        
        
        pb=realloc(pb,(j+2));
       pb[j++]=b;
        
        
    }
    pb[j] = '\0';
    printf("%s", pa);
printf("%s", pb);
}