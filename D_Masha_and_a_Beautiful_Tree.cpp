#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol q(lol p[], lol l, lol r, lol mn, lol mx)
{   
    if (l == r)
    {
        if (p[l] != mn)
            return -1;
        else
            return 0;
    }
    map<lol, lol> mp1, mp2;
    lol v1 = mn, v2 = mx;
    for (lol i = l; i <= (l + r) / 2; i++)
    {
        mp1[p[i]]++;
        if (mp1[p[i]] == 0)
            mp1.erase(p[i]);
        mp1[v1]--;
        if (mp1[v1] == 0)
            mp1.erase(v1);
        v1++;
        mp2[p[i]]++;
        if (mp2[p[i]] == 0)
            mp2.erase(p[i]);
        mp2[v2]--;
        if (mp2[v2] == 0)
            mp2.erase(v2);
        v2--;
    }
    if (mp1.size() == 0)
    {
        lol a = q(p, l, (l + r) / 2, mn, mn + (l + r) / 2-l);
        lol b = q(p, (l + r) / 2 + 1, r, mn + (l + r) / 2-l+1, mx);
        if (a == -1 || b == -1)
            return -1;
        return a + b;
    }
    else if (mp2.size() == 0)
    {
        lol a = q(p, l, (l + r) / 2, mn + (l + r) / 2-l+1, mx);
        lol b = q(p, (l + r) / 2 + 1, r, mn, mn + (l + r) / 2-l);
        if (a == -1 || b == -1)
            return -1;
        return a + b + 1;
    }
    else
        return -1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol m;
        cin >> m;
        lol p[m];
        for (lol i = 0; i < m; i++)
        {
            cin >> p[i];
        }
        cout << q(p, 0, m - 1, 1, m) << endl;
    }

    return 0;
}