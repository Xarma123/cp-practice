#include <stdio.h>
#include <string.h>
#include <conio.h>
int main()
{   char str[25];
gets(str);
lol p,n;
scanf("%d %d",&p,&n);
   if(n==0)puts(str);
   else{
 for (lol i = p-1; i <= p-1+n-1&&i<strlen(str); i++)
 {        prlolf("%c",str[i]);
       
 }
 


   }




  getch();




}