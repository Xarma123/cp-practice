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
        lol n;
        cin >> n;
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool visit[n][n];
        memset(visit, false, sizeof(visit));
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                if (visit[i][j])
                    continue;
                lol o = 0, z = 0;
                set<pair<lol, lol>> x;
                x.insert({i, j});
                // x.insert({n - i - 1, j});
                x.insert({n - i - 1, n - j - 1});
                // x.insert({i, n - j - 1});
                swap(i, j);
                // x.insert({i, j});
                x.insert({n - i - 1, j});
                // x.insert({n - i - 1, n - j - 1});
                x.insert({i, n - j - 1});
                swap(i, j);
                for (auto p : x)
                {
                    lol a1 = p.first;
                    lol b1 = p.second;
                    visit[a1][b1] = true;
                    if (a[a1][b1] == '0')
                        z++;
                    else
                        o++;
                }
                ans += min(o, z);
            }
        }

        cout << ans << endl;
    }

    return 0;
}