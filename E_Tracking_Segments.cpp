#include <bits/stdc++.h>
using namespace std;
#define lol long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        vector<pair<lol, lol>> v(m);
        for (lol i = 0; i < m; i++)
        {
            cin >> v[i].first >> v[i].second;
        }
        // m*t

        lol q;
        cin >> q;
        vector<lol> ind(q);
        for (lol i = 0; i < q; i++)
        {
            cin >> ind[i];
        }

        // q*t

        // m

        lol s = -1, e = ind.size();
        while (s != e - 1)
        {
            lol md = (s + e) / 2;
            if (md == -1)
            {
                s = md;
            }
            else if (md == (long long)ind.size())
            {
                e = md;
            }
            else
            {
                vector<lol> a(n, 0);
                for (lol i = 0; i <= md; i++)
                {
                    a[ind[i] - 1]++;
                }
                lol c[n + 1];
                c[0] = 0;
                for (lol i = 1; i <= n; i++)
                {
                    c[i] = c[i - 1] + a[i - 1];
                }
                bool f = false;
                for (auto seg : v)
                {
                    lol acha = c[seg.second] - c[seg.first - 1];
                    if ((acha > ((seg.second - seg.first + 1) / 2)))
                    {
                        e = md;
                        f = true;
                        break;
                    }
                }
                if (!f)
                    s = md;
            }
        }

        if (e == ind.size())
        {
            e = -1;
        }
        else
            e++;

        cout << e << '\n';
    }
}