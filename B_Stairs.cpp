#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    lol t;
    cin >> t;
    while (t--)
    {

        lol x;
        cin >> x;
        lol v = 1;
        lol c = 2;
        lol ans = 0;
        while ( ((x - (v*1ll*(v+1)/2)) >= 0) )
        {
            x = x - (v*1ll*(v+1)/2);
            ans++;
            v += c;
            c = c * 1ll * 2;
        } 
        cout<<ans<<endl;
    }

    return 0;
}