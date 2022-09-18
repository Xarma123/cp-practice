#include<iostream>
#include<cmath>

using namespace std;
int main()
{
    long long lol n;
    cin>>n;long long lol k = 0  ; long long lol i = 0 ; 
    while (n)
    {   
       if(n%10==7)
         k=k|(1<<i);
         i++;
         n=n/10;
    } 
    cout<<(k+pow(2,i)-1)<<endl;
    
    
}