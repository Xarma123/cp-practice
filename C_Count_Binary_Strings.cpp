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
    lol a[n + 1][n + 1];
    for (lol i = 1; i <= n; i++)
    {
        for (lol j = i; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    bool police = false;
    for (lol i = 1; i <= n; i++)
    {
        for (lol j = i; j <= n; j++)
        {
            if (a[i][j] == 1)
            {
                for (lol i1 = i; i1 <= j; i1++)
                {
                    for (lol j1 = i1; j1 <= j; j1++)
                    {
                        if (a[i1][j1] > 1)
                        {
                            police = true;
                        }
                    }
                }
            }
        }
    }
    if (police)
        cout << 0;
    else
    {
        vector<pair<lol, lol>> f;
        for (lol i = 1; i <= n; i++)
        {
            f.push_back({i, i});
        }

        for (lol len = 0; len < 2 && !police; len++)
        {
            for (lol i = 1, j = len + 1; j <= n && !police; i++, j++)
            {
                if (i == j)
                {
                    if (a[i][j] == 2)
                        police = true;
                }
                else
                {
                    if (a[i][j])
                    {
                        for (lol k = 0; k < f.size(); k++)
                        {
                            if (f[k].first >= i && f[k].second <= i)
                            {

                                lol k2 = k;
                                while (!(f[k2].first >= j && f[k2].second <= j))
                                    k2++;
                                if (k != k2)
                                {

                                    pair<lol, lol> nw = {f[k].first, f[k2].second};
                                    f.erase(f.begin() + k + 1, f.begin() + k2 + 1);
                                    f[k] = nw;
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (police)
            cout << 0;
        else
        {
            lol ans = 1;
            lol mod = 998244353;
            for (lol i = 1; i < f.size(); i++)
            {
                ans = (ans * 2ll) % mod;
            }
            cout << ans;
        }
    }

    return 0;
}