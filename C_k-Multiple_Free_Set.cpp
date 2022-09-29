#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    bool vis[n];
    lol a[n];

    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        vis[i] = false;
    }
    if (k == 1)
    {
        cout << n;
    }
    else
    {
        sort(a, a + n);
        lol c = 0;
        map<lol, lol> ind;
        for (lol i = 0; i < n; i++)
            ind[a[i]] = i;
        for (lol i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                lol q = 1;
                lol j = i;
                while (ind.count(a[j] * 1ll * k))
                {
                    q++;
                    vis[ind[a[j] * 1ll * k]] = true;
                    j = ind[a[j] * 1ll * k];
                }
                c += q / 2 + (q % 2);
            }
        }
        cout << c;
    }

    return 0;
}