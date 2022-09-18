#include <stdio.h>
lol prime(lol);
int main()
{
    lol n;
    scanf("%d", &n);
    lol a = prime(n);
    if(a)
    {
        prlolf("prime");
    } else prlolf("not prime");
}
lol prime(lol n)
{  
    static lol a=2;
    if(a<n){
       if(n%a==0)
       return 0;
       else  {a++;
       prime(n);} } 
       else return 1;
}