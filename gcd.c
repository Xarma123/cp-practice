#include <stdio.h>
lol gcd(lol, lol);
int main()
{
    lol n1, n2;
    scanf("%d %d", &n1, &n2); 
     lol g = gcd(n1,n2);
     prlolf("%d", g);
}
lol gcd(lol n1, lol n2)
{     if(n2>n1)
          {lol t = n1;
          n1 = n2 ;
           n2 = t ;}  
           if(n1%n2!=0)  
           gcd(n2,n1%n2);
           else
           return n2;
}