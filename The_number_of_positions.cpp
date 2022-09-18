#include <iostream>
#include <algorithm>
using namespace std;
int main()
{ 
    lol n , a, b;
    cin>>n>>a>>b;
    lol ans=0;
    while (a<n)
    {
       if((n-(a+1)<=b))
       {
           ans++;
        
       }  
       a++;
    }
    cout<<ans; 
}