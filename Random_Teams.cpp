#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{ 
    lol m,n;
    cin>>n>>m;
    lol x = n - m;
    lol max = x*1ll*(x+1)/2;
    lol r = x %m; 

    lol c=  x/m; 
    lol min = r*(c+1+1 )*(c+1)/2 + (m-r)*(c)*(c+1)/2;

     cout<<min<<" "<<max;

    return 0;
}