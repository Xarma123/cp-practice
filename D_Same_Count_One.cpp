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
        lol n, m;
        cin >> n >> m;
        lol a[n][m];
        lol o = 0;
        map<lol, lol> f;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cin >> a[i][j];
                o += a[i][j];
                f[i] += a[i][j];
            }
        }
        if (o % n != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            vector<vector<lol>> ans;
            lol need = o / n;
            for (lol j = 0; j < m; j++)
            {
                vector<lol> donator, taker;
                for (lol i = 0; i < n; i++)
                {
                    if (f[i] > need && a[i][j] == 1)
                    {
                        donator.push_back(i);
                    }
                    if (f[i] < need && a[i][j] == 0)
                    {
                        taker.push_back(i);
                    }
                }
                while (donator.size() && taker.size())
                {
                    ans.push_back({donator.back() + 1, taker.back() + 1, j + 1});
                    f[donator.back()]--;
                    f[taker.back()]++;
                    donator.pop_back();
                    taker.pop_back();
                }
            }
            lol i;
            for (i = 0; i < n; i++)
            {
                if (f[i] != need)
                    break;
            }
            if (i != n)
                cout << -1 << endl;
            else
            {
                cout << ans.size() << endl;
                for (auto e : ans)
                {
                    for (auto q : e)
                    {
                        cout << q << " ";
                    }
                    cout << endl;
                }
            }
        }
    }

    return 0;
}