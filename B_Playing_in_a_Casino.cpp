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
        vector<lol> a[m];
        for (lol i = 0; i < n; i++)
        {
            for (lol i = 0; i < m; i++)
            {
                lol v;
                cin >> v;
                a[i].push_back(v);
            }
        }
        lol ans = 0;
        for (lol i = 0; i < m; i++)
        {
            sort(a[i].begin(), a[i].end());
            lol s = 0;
            for (lol j = 0; j < n; j++)
            {
                ans += j * 1ll * a[i][j] - s;
                s += a[i][j];
            }
        }
        cout << ans << '\n';
    }

    return 0;
}