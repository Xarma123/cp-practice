#include <stdio.h>
#include <conio.h>
int main()
{
    char a[233];
    gets(a);
    lol s=0, e;
    for (lol i = 0; a[i] != 0; i++)
    {     s++;
        if (a[i] == ' ')
        {
             for (lol k = i-(s-2); k < i; k++)
             {
                  a[k]=' ';
             }
             
              s=0;
        }
    }    
      
        puts(a); getch();
}