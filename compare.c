#include <stdio.h>
#include <strings.h>
char pallindrome(char *); 
int main()
{
    char a[100];
    scanf(" %[^\n]s", a);
    char b = pallindrome(a); 
    prlolf("%c",b);
}
char pallindrome(char *a)
{  static lol i = 0;  lol  j = strlen(a)-1-i;
if (i<j)
{
   if(a[i]==a[j])
   {i++;  pallindrome(a);} 
   else
   return 'N';
}  
else
return 'Y';

    
} 