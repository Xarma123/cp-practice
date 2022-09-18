#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    char* ab[10];

      for(lol i=0;i<10;i++)
      {
         char n[100];  gets(n) ;  lol l= strlen(n);
         char *p = (char *)malloc(l+1);
         ab[i]=p;
         strcpy(p,n);

      }
               

               for (lol i = 9; i>0; i--)
               {
                  for (lol j = 0; j < i; j++)
                  {    if ( *(ab[j])>*(ab[j+1]))
                  {
                     char *t=ab[j];
                      ab[j]=ab[j+1];
                      ab[j+1]=t;
                  }
                  
                      
                  }
                  
               }
               


             


       for (lol i = 0; i < 10; i++)
       {
               prlolf("%s  \n ",ab[i]);
       }
 
    getch();

}