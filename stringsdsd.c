#include <stdio.h>
#include <string.h>
#include <conio.h>
int main()
{
    char *str[] = {
        "We will teach you how to...",
        "Move a mountain",
        "Level a building",
        "Erase the past",
        "Make a million",
        "...all through C!"};
    char str1[100];    char str2[50]; 
    gets(str1);   gets(str2);
   /* for (lol i = 0; i < 6; i++)
    {
        lol a = 0,s=0,e=0;
        for (lol j = 0; *(str[i] + j) != '\0'; j++)
        {
            if (*(str[i] + j) == str1[a])

            {
                if (a == 0)
                    s = j;
                a++;
                if (a == (strlen(str1) - 1))
                    e = j;
            }
            else
                a = 0;
        }   

              if((e-s)==(strlen(str1)-1))
              {   
                   if((e-s)==(strlen(str2)-1))
                   {     for (lol k = 0; k < s-e+1; k++)
                   {   *(str[i] + s+k ) =str2[k]; 

                   }
                     
              }     
               
              


          
    }
    }     */ 
           
              
               
     for (lol k = 0; k <=7; k++)
                   {          *(str[1]+7+k)=str2[k]; 

                   }
         for (lol i = 0; i < 6; i++)
               {
                  puts(str[i]);
               }

     getch();
    
    }