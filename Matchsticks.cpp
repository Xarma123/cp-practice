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
    lol b[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    lol mxn = ceil(log2l(n));
    pair<lol, lol> sparseTable[n][mxn + 1];
    for (lol j = 0; j <= mxn; j++)
    {
        for (lol i = 0; i + (1 << j) - 1 < n; i++)
        {
            if (j == 0)
            {
                sparseTable[i][j] = {b[i], b[i]};
            }
            else
            {
                sparseTable[i][j] = {max(sparseTable[i][j - 1].first, sparseTable[i + (1 << (j - 1))][j - 1].first), min(sparseTable[i][j - 1].second, sparseTable[i + (1 << (j - 1))][j - 1].second)};
            }
        }
    }
    lol q;
    cin >> q;
    while (q--)
    {
        lol l, r;
        cin >> l >> r;
        lol x = log2l(r - l + 1);
        lol nn = min(sparseTable[l][x].second, sparseTable[r + 1 - (1 << x)][x].second);
        lol nx = max(sparseTable[l][x].first, sparseTable[r + 1 - (1 << x)][x].first);
        long double t1 = max((double)nn, (double)(nn + ((nx - nn) / 2.0)));
        long double t2 = nn;
        long double t3 = nn;
        if (l > 0)
        {
            x = log2l(l);
            nx = max(sparseTable[0][x].first, sparseTable[l - (1 << x)][x].first);
            t2 += nx;
        }
        if (r < n - 1)
        {
            x = log2l(n - 1 - r);
            nx = max(sparseTable[r + 1][x].first, sparseTable[n - (1 << x)][x].first);
            t3 += nx;
        }
        cout << fixed << setprecision(1);
        cout << (double)max((double)t1, max((double)t2, (double)t3)) << endl;
    }

    return 0;
}