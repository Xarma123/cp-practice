#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        string b[n - 1];
        for (lol i = 0; i < n - 1; i++)
        {
            cin >> b[i];
        }
        string ans = "";
        for (lol j = 0; j < m; j++)
        {
            map<char, lol> mp;
            for (lol i = 0; i < n; i++)
            {
                mp[a[i][j]]++;
            }
            for (lol i = 0; i < n - 1; i++)
            {
                mp[b[i][j]]--;
                if (mp[b[i][j]] == 0)
                    mp.erase(b[i][j]);
            }
            ans += (*mp.begin()).first;
        }
        cout << ans << '\n';
    }
}