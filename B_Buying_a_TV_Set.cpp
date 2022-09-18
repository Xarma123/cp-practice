#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol a, b, x, y;
    cin >> a >> b >> x >> y; 
    if(y%x==0)
    cout<<min(a,(b*x)/y);
    else
    {
        lol v = min(a,(b*x)/y);
        lol ans=0;
        for (lol i = x; i/y <=v; i++)
        {
            if(i%y==0)
            ans++;
        }
        cout<<ans;
        
    }

    return 0;
}