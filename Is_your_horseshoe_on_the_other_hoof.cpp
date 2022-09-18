#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{ 
    lol a[4]; lol n =4;
    for (lol i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
     lol ans=0; 

     sort(a,a+n);
    for (lol i = 0; i <n; i++)
    {  if(a[i]==a[i+1])
        ans++;
    }
    cout<<ans;
}
