#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol spb[200005][30];
lol spa[200005][30];
lol ln[200005];
lol mn(lol i, lol j)
{
    return min(spb[i][ln[j - i + 1]],
               spb[j - (1ll << ln[j - i + 1]) + 1][ln[j - i + 1]]);
}
lol mx(lol i, lol j)
{
    return max(spa[i][ln[j - i + 1]],
               spa[j - (1ll << ln[j - i + 1]) + 1][ln[j - i + 1]]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        ln[1] = 0;
        for (lol i = 2; i <= n; i++)
        {
            ln[i] = ln[i / 2] + 1;
        }
        lol a[n];
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (lol j = 0; j < 30; j++)
        {
            for (lol i = 0; i < n && i + (1ll << j) - 1 < n; i++)
            {
                if (j == 0)
                    spa[i][j] = a[i];
                else
                    spa[i][j] = max(spa[i][j - 1], spa[i + (1ll << (j - 1))][j - 1]);
            }
        }
        for (lol j = 0; j < 30; j++)
        {
            for (lol i = 0; i < n && i + (1ll << j) - 1 < n; i++)
            {
                if (j == 0)
                    spb[i][j] = b[i];
                else
                    spb[i][j] = min(spb[i][j - 1], spb[i + (1ll << (j - 1))][j - 1]);
            }
        }
     
        bool ans[n];
        memset(ans, false, sizeof(ans));

        map<lol, lol> ind;
        for (lol i = 0; i < n; i++)
        {
            ind[a[i]] = i;
            if (ind.count(b[i]))
            {
                lol j = ind[b[i]];
                if (mx(j, i) == mn(j, i) && mx(j, i) == b[i])
                    ans[i] = true;
            }
        }
        ind.clear();
        for (lol i = n - 1; i >= 0; i--)
        {
            ind[a[i]] = i;
            if (ind.count(b[i]))
            {
                lol j = ind[b[i]];

                if (mx(i, j) == mn(i, j) && mx(i, j) == b[i])
                    ans[i] = true;
            }
        }
        bool f = true;
        for (lol i = 0; i < n; i++)
        {
            f &= ans[i];
        }
        if (f)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
