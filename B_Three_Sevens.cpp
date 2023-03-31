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
        lol m;
        cin >> m;
        vector<lol> a[m];
        for (lol i = 0; i < m; i++)
        {
            lol n;
            cin >> n;
            a[i].resize(n);
            for (lol j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        set<lol> x;
        vector<lol> ans;
        for (lol i = m - 1; i >= 0; i--)
        {
            bool f = true;
            for (lol j = 0; j < a[i].size(); j++)
            {
                if (!x.count(a[i][j]))
                {
                    if (f)
                        ans.push_back(a[i][j]), f = false;
                }
                x.insert(a[i][j]);
            }
        }
        if (ans.size() == m)
        {
            for (lol i = m - 1; i >= 0; i--)
            {
                cout << ans[i] << " ";
            }
            cout << '\n';
        }
        else
            cout << -1 << '\n';
    }

    return 0;
}