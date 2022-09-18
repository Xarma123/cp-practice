#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
int main()
{

    char *stri[] =
        {"We will teach you how to....",
         "Move a mountain",
         "Level a building",
         "Erase the past",
         "Make a million",
         "...all through C!"};

    char *str[2];
    char s[20];
    lol n;
    char *p;
    for (lol i = 0; i < 2; i++)
    {  scanf("%[^\n]s",s);
    n= strlen(s);
    p=(char*)malloc(n+1);
          strcpy(p,s);
          str[i]=p;
    }   
        
           for (lol j = 0; j < 6; j++)
           { lol a =  strcmp(stri[j],str[0]);
                 if(a==0) {
                     *stri[j]=*str[1];
                 }
           }
           
         
         for (lol i = 0; i < 6; i++)
         {
           prlolf("%s",stri[i]);
         }
         
  getch();

}