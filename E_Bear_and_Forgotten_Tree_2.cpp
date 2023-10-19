#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    map<lol, lol> mp;
    while (m--)
    {
        lol x, y;
        cin >> x >> y;
        mp[x]++;
        mp[y]++;
    }
    bool ans = true;
    for (lol i = 1; i <= n; i++)
    {
        lol r = n - 1 - mp[i];
        if (i == 1)
        {
            if (r < k)
                ans = false;
        }
        if (r == 0)
            ans = false;
    }
    if (ans)
    {
        
    }

    return 0;
}
