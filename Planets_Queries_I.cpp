#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol parent[200001][31];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    for (lol i = 1; i <= n; i++)
    {
        cin >> parent[i][0];
    }
    for (lol d = 1; d < 31; d++)
    {
        for (lol i = 1; i <= n; i++)
        {
            parent[i][d] = parent[parent[i][d - 1]][d - 1];
        }
    }
    while (q--)
    {
        lol x, k;
        cin >> x >> k;
        lol c = x;
        for (lol i = 0; i < 31; i++)
        {
            if (k & (1 << i))
            {
                c = parent[c][i];
            }
        }
        cout << c << '\n';
    }

    return 0;
}