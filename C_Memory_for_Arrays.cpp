#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol f, b[m];
    map<lol, lol> x;
    for (lol i = 0; i < n; i++)
    {
        cin >> f;
        x[f]++;
    }
    for (lol i = 0; i < m; i++)
    {
        cin >> b[i];
        b[i] = (1ll << b[i]);
    }
    sort(b, b + m);
    lol ans = 0;
    for (lol i = 0; i < m; i++)
    {

        auto it = x.lower_bound(b[i]);
        if (it != x.end())
        {
            ans++;
            lol v = (*it).first;
            if (--(*it).second == 0)
            {
                x.erase(it);
            }
            v -= b[i];
            x[v]++; 
        }
    }
    cout << ans;

    return 0;
}