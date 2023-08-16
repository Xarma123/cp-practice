#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m, d;
        cin >> n >> m >> d;
        vector<lol> p;
        p.push_back(1);
        bool f = false;
        while (m--)
        {
            lol c;
            cin >> c;
            if (c == 1)
                f = true;

            if (p.back() != c)
                p.push_back(c);
        }
        p.push_back(n + 1);
        lol pr[p.size()];
        for (lol i = 0; i < p.size() - 1; i++)
        {
            lol v = 1;
            v += ceill((p[i + 1] - p[i]) / (long double)d) - 1;
            pr[i] = v;
            if (i - 1 >= 0)
                pr[i] += pr[i - 1];
        }
        lol suf[p.size()];
        suf[p.size() - 1] = 0;
        for (lol i = p.size() - 2; i >= 0; i--)
        {
            lol v = 1;
            v += ceill((p[i + 1] - p[i]) / (long double)d) - 1;
            suf[i] = v;
            suf[i] += suf[i + 1];
        }
        lol ans = LONG_LONG_MAX;
        lol co = 0;
        for (lol i = 1; i < p.size() - 1; i++)
        {
            lol v = pr[i - 1] + suf[i + 1];
            lol v2 = 1;
            v2 += ceill((p[i] - p[i - 1]) / (long double)d) - 1;
            v -= v2;
            v++;
            v += ceill((p[i + 1] - p[i - 1]) / (long double)d) - 1;
            if (ans > v)
            {
                co = 1;
            }
            else if (ans == v)
                co++;
            ans = min(ans, v);
        }
        if (suf[0] == ans && f)
            co++;
        cout << ans << ' ' << co << '\n';
    }
}