#include <stdio.h>
#include <conio.h>
int main()
{
    char a[100];
    gets(a);  lol a1=0;char arr[22]; lol i =0;
    char vowels[11] = "AaEeIiOoUu";
    for (lol i = 0; a[i] != '\0'; i++)
    {
        for (lol j = 0; vowels[j] != '\0'; j++)
        {    if(a[i]==vowels[j])
             {  arr[a1]=a[i];
                 a1++;
                 
             }   else
           i++;
        }   
          if(i==10)
          {a1=0;}
            if((i!=10)&&a1==2)
            {for (lol x = 0; x < 2; x++)
            {
               prlolf("%c",arr[x]);
            }  prlolf("\n");
            }
          

    }   getch();
}