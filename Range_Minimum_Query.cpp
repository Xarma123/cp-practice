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
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol mx = ceill(log2l(n));
    lol sparsetable[n][mx + 1];
    for (lol i = 0; i < n; i++)
    {
        sparsetable[i][0] = a[i];
    }
    for (lol j = 1; j <= mx; j++)
    {
        for (lol i = 0; i < n && i + (1 << j) - 1 < n; i++)
        {
            sparsetable[i][j] = min(sparsetable[i][j - 1], sparsetable[i + (1 << (j - 1))][j - 1]);
        }
    }
    lol q;
    cin >> q;
    while (q--)
    {
        lol a, b;
        cin >> a >> b;
        lol x = log2l(b - a + 1);
        cout << min(sparsetable[a][x], sparsetable[b + 1 - (1 << x)][x]) << endl;
    }

    return 0;
}