#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol sparse[200005][30];
lol n, m;
lol mx(lol l, lol r)
{
    lol v = log2l(r - l + 1);
    return max(sparse[l][v], sparse[r - (1ll << v) + 1][v]);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    lol a[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    for (lol i = 0; i < m; i++)
    {
        sparse[i][0] = a[i];
    }

    for (lol j = 1; j < 30; j++)
    {
        for (lol i = 0; i < m; i++)
        {
            if (i + (1ll << j) - 1 < m)
                sparse[i][j] = max(sparse[i][j - 1], sparse[i + (1ll << (j - 1))][j - 1]);
        }
    }
    lol q;
    cin >> q;
    while (q--)
    {
        lol r, c;
        cin >> r >> c;
        lol dr, dc;
        cin >> dr >> dc;
        lol k;
        cin >> k;
        if (((abs(dr - r)) % k == 0) && ((abs(dc - c)) % k == 0))
        {
            lol up = ((n - r) / k) * 1ll * k + r;
            if (c > dc)
                swap(c, dc);
            if (mx(c - 1, dc - 1) < up)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
        else
            cout << "NO\n";
    }

    return 0;
}