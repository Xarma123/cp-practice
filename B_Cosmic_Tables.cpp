#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    lol a[n][m];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    lol r[n];
    lol c[m];
    for (lol i = 0; i < n; i++)
    {
        r[i] = i;
    }
    for (lol i = 0; i < m; i++)
    {
        c[i] = i;
    }

    while (k--)
    {
        char q;
        cin >> q;
        lol x, y;
        cin >> x >> y;
        x--;
        y--;
        if (q == 'c')
        {
            swap(c[x], c[y]);
        }
        else if (q == 'r')
            swap(r[x], r[y]);
        else
        {
            cout << a[r[x]][c[y]] << '\n';
        }
    }

    return 0;
}