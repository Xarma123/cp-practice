#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, p, q, r;
    cin >> n >> p >> q >> r;
    lol c[n + 1];
    c[0] = 0;
    for (lol i = 0; i < n; i++)
    {
        lol a;
        cin >> a;
        c[i + 1] = c[i] + a;
    }
    map<lol, lol> mp;
    mp[0] = 0;
    bool pex[n + 1];
    memset(pex, false, sizeof(pex));
    lol qind[n + 1];
    memset(qind, -1, sizeof(qind));
    lol rind[n + 1];
    memset(rind, -1, sizeof(rind));

    for (lol i = 1; i <= n; i++)
    {
        if (mp.count(c[i] - p))
        {
            pex[i] = true;
        }
        if (mp.count(c[i] - q))
        {
            qind[i] = mp[c[i] - q];
        }
        if (mp.count(c[i] - r))
        {
            rind[mp[c[i] - r]] = i;
        }
        mp[c[i]] = i;
    }
    bool ans = false;
    for (lol i = 1; i <= n; i++)
    {
        if (rind[i] != -1 && qind[i] != -1 && pex[qind[i]])
        {
            ans = true;
            break;
        }
    }
    if (ans)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}