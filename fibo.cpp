#include<iostream>
using namespace std;
lol fibo(lol n )
{    if (n==1)
     return 0;
     if (n==2)
     
         return 1;
     
    return (fibo(n-1) + fibo(n-2) );
   


    
    }
int main()
{  while (1)
{
     lol c; cin>>c;
     cout<<fibo(c);
}


}