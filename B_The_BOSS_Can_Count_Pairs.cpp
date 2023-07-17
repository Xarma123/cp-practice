#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n], b[n];
        map<lol, vector<lol>> mp;
        map<lol, lol> co[n + 1];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]].push_back(i);
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (lol i = 0; i < n; i++)
        {
            co[a[i]][b[i]]++;
        }
        lol ans = 0;

        for (lol i = 1; i * 1ll * i <= 2ll * n; i++)
        {
            for (lol j = 1; j * 1ll * i <= 2ll * n; j++)
            {

                lol s = j;
                lol f = i;
                lol v = 0;
                for (auto e : mp[f])
                {
                    if (s <= n)
                    {
                        v += co[s][(i * 1ll * j) - b[e]];
                        
                    }
                }
                
                ans += v;
            }
        }
        cout<<ans<<'\n';
        
    }
}