#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, q;
        cin >> n >> q;
        lol a[n];
        vector<lol> ind;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i])
                ind.push_back(i + 1);
        }

        lol c[n + 1];
        c[0] = 0;
        for (lol i = 1; i <= n; i++)
        {
            c[i] = c[i - 1] + a[i - 1];
        }
        lol x[n + 1];
        x[0] = 0;
        for (lol i = 1; i <= n; i++)
        {
            x[i] = x[i - 1] ^ a[i - 1];
        }
        while (q--)
        {
            lol L, r;
            cin >> L >> r;

            if (c[r] - c[L - 1] == 0)
                cout << L << " " << L << '\n';
            else
            {
                lol a1 = -1, a2;
                lol j = lower_bound(ind.begin(), ind.end(), L) - ind.begin();
                lol co = 0;
                for (; co < 60 && j < ind.size() && ind[j] <= r; j++)
                {
                    lol l = ind[j];
                    co++;
                    lol v = c[r] - c[l - 1] - (x[r] ^ x[l - 1]);
                    if (v != c[r] - c[L - 1] - (x[r] ^ x[L - 1]))
                        break;
                    lol s = l - 1, e = r;
                    while (s != e - 1)
                    {
                        lol m = (s + e) / 2;
                        if (m == l - 1)
                        {
                            s = m;
                        }
                        else
                        {
                            if (v == c[m] - c[l - 1] - (x[m] ^ x[l - 1]))
                                e = m;
                            else
                                s = m;
                        }
                    }
                    if (a1 == -1)
                    {
                        a1 = l;
                        a2 = e;
                    }
                    else if (a2 - a1 > e - l)
                    {
                        a1 = l;
                        a2 = e;
                    }
                }
                cout << a1 << " " << a2 << '\n';
            }
        }
    }

    return 0;
}