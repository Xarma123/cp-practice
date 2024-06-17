#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol a[n][m];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        lol b[n][m];
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cin >> b[i][j];
                mp[b[i][j]] = i;
            }
        }
        bool ans = true;
        for (lol i = 0; i < n && ans; i++)
        {
            lol ii = mp[a[i][0]];
            map<lol, lol> f;
            for (lol j = 0; j < m; j++)
            {
                f[a[i][j]]++;
            }
            for (lol j = 0; j < m; j++)
            {
                if (--f[b[ii][j]] == 0)
                {
                    f.erase(b[ii][j]);
                }
            }
            if (f.size() != 0)
            {
                ans = false;
                break;
            }
            for (lol j = 0; j < m; j++)
            {
                f[b[ii][j]] = j;
            }
            for (lol j = 0; j < m; j++)
            {
                a[i][j] = f[a[i][j]];
            }
            if (i)
            {
                for (lol j = 0; j < m; j++)
                {
                    if (a[i][j] != a[i - 1][j])
                    {
                        ans = false;
                        break;
                    }
                }
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
