#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> re(lol n, vector<vector<lol>> qry)
{
    lol ans[n];
    memset(ans, 0, sizeof(ans));
    lol c[n];
    memset(c, 0, sizeof(c));
    for (auto e : qry)
    {
        ans[e[0]] += e[1];
        lol j = min(e[0] + e[1] - 1, n - 1);
        if (j + 1 < n)
            c[j + 1]++;
    }
    lol sub = 0;
    for (lol i = 0; i < n; i++)
    {
        if (ans[i] > 0)
            sub++;
        if (i)
            ans[i] += ans[i - 1];
        ans[i] -= sub - 1;
        ans[i] += c[i];
    }
    lol ans2[n];
    memset(ans2, 0, sizeof(ans2));
    memset(c, 0, sizeof(c));
    for (auto e : qry)
    {
        ans2[e[0]] += e[1];
        lol j = max(e[0] - (e[1] - 1), 0ll);
        if (j - 1 >= 0)
            c[j - 1]++;
    }
    sub = 0;
    for (lol i = n - 1; i >= 0; i--)
    {
        if (ans2[i] > 0)
            sub++;
        if (i < n - 1)
            ans2[i] += ans2[i + 1];
        ans2[i] -= sub - 1;
        ans2[i] += c[i];
    }
    lol v[n];
    memset(v, 0, sizeof(v));
    for (auto e : qry)
        v[e[0]] += e[1];
    vector<lol> f(n);
    for (lol i = 0; i < n; i++)
    {
        f[i] = ans[i] + ans2[i] - v[i];
    }
    return f;
}
int main()
{
   

    return 0;
}