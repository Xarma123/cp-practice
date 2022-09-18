#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m;
    cin >> n >> m;
    lol ans = LONG_LONG_MIN;
    for (lol i = 0; i < n; i++)
    {
        lol c = LONG_LONG_MAX;
        for (lol j = 0; j < m; j++)
        {
            lol t;
            cin >> t;
            c = min(c, t);
        }
        ans=max(ans,c);
    } 
    cout<<ans;

    return 0;
}