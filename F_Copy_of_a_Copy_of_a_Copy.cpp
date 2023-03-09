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
    vector<vector<string>> a;
    for (lol i = 0; i < k + 1; i++)
    {
        vector<string> q;
        for (lol j = 0; j < n; j++)
        {
            string x;
            cin >> x;
            q.push_back(x);
        }
        a.push_back(q);
    }
    pair<lol, lol> c[k + 1];
    for (lol i = 0; i < k + 1; i++)
    {
        lol q = 0;
        for (lol j = 1; j < n - 1; j++)
        {
            for (lol j1 = 1; j1 < m - 1; j1++)
            {
                if (a[i][j - 1][j1] != a[i][j][j1] && a[i][j - 1][j1] == a[i][j + 1][j1] && a[i][j + 1][j1] == a[i][j][j1 - 1] && a[i][j][j1 - 1] == a[i][j][j1 + 1])
                {
                    q++;
                }
            }
        }
        c[i] = make_pair(-q, i + 1);
    }
    sort(c, c + k + 1);
    cout << c[0].second << endl;
    vector<vector<lol>> ans;

    for (lol i = 1; i < k + 1; i++)
    {
        bool f = true;
        for (lol j = 1; j < n - 1; j++)
        {
            for (lol j1 = 1; j1 < m - 1; j1++)
            {
                if (a[c[i - 1].second - 1][j - 1][j1] != a[c[i - 1].second - 1][j][j1] && a[c[i - 1].second - 1][j - 1][j1] == a[c[i - 1].second - 1][j + 1][j1] && a[c[i - 1].second - 1][j + 1][j1] == a[c[i - 1].second - 1][j][j1 - 1] && a[c[i - 1].second - 1][j][j1 - 1] == a[c[i - 1].second - 1][j][j1 + 1])
                {
                    if (a[c[i].second - 1][j - 1][j1] == a[c[i].second - 1][j][j1] && a[c[i].second - 1][j - 1][j1] == a[c[i].second - 1][j + 1][j1] && a[c[i].second - 1][j + 1][j1] == a[c[i].second - 1][j][j1 - 1] && a[c[i].second - 1][j][j1 - 1] == a[c[i].second - 1][j][j1 + 1])
                    {

                        if (a[c[i].second - 1][j][j1] != a[c[i - 1].second - 1][j][j1])
                        {
                            // cout << 1 << " " << j + 1 << " " << j1 + 1 << '\n';
                            ans.push_back({1, j + 1, j1 + 1});
                        }
                    }
                }
            }
        }
        ans.push_back({2, c[i].second});
        // cout << 2 << " " << c[i].second << endl;
    }
    cout << ans.size() << endl;
    for (auto e : ans)
    {
        for (auto f : e)
            cout << f << " ";
        cout << endl;
    }

    return 0;
}