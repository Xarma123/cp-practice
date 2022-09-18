#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    lol n; cin>>n;
    lol a[n];
    lol min = INT_MAX;
    lol ans;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        if (min > a[i])
        {
            ans = i;
            min = a[i];
        }
        else if(min==a[i])
        { ans=-1;
            
        }
    } 
    if(ans==-1)
     cout<<"Still Rozdil";
     else
     cout<<ans+1;
}