#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol p[n], q[n];
    lol fp[n + 1];
    lol fq[n + 1];
    for (lol i = 0; i < n; i++)
    {
        cin >> p[i];
        fp[p[i]] = i;
    }
    for (lol i = 0; i < n; i++)
    {
        cin >> q[i];
        fq[q[i]] = i;
    }
    lol x = fp[1];
    lol y = fq[1];
    lol ans = 0;
    if (x > y)
        swap(x, y);
    ans += x * 1ll * (x + 1) / 2ll;
    ans += (n - 1 - y) * 1ll * (n - y) / 2ll;
    ans += (y - x - 1) * 1ll * (y - x) / 2ll;
    set<lol> px, qx;
    for (lol i = x; i <= y; i++)
    {
        px.insert(p[i]);
        qx.insert(q[i]);
    }
    lol mex;
    for (mex = 1; mex <= n; mex++)
    {
        if (px.find(mex) != px.end() && qx.find(mex) != qx.end())
            continue;
        else
            break;
    }
    while (mex != n + 1)
    {
        if (px.find(mex) == px.end() && qx.find(mex) == qx.end())
        {
            lol l = -1;
            if (fp[mex] < x)
            {
                l = max(l, fp[mex]);
            }
            if (fq[mex] < x)
                l = max(l, fq[mex]);
            lol r = n;
            if (fp[mex] > y)
            {
                r = min(r, fp[mex]);
            }
            if (fq[mex] > y)
                r = min(r, fq[mex]);
            ans += (x - l) * 1ll * (r - y);
        }

        lol l = min(x, min(fp[mex], fq[mex]));
        lol r = max(y, max(fp[mex], fq[mex]));
        for (lol i = l; i < x; i++)
        {
            px.insert(p[i]);
            qx.insert(q[i]);
        }
        for (lol i = y + 1; i <= r; i++)
        {
            px.insert(p[i]);
            qx.insert(q[i]);
        }
        x = l, y = r;
        while (px.find(mex) != px.end() && qx.find(mex) != qx.end())
            mex++;
    }
    cout << ans + 1;

    return 0;
}