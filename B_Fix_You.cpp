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
        lol ans = 0;
        for (lol j = 0; j < m - 1; j++)
        {
            if (a[n - 1][j] != 'R')
                ans++;
        }
        for (lol i = 0; i < n - 1; i++)
        {
            if (a[i][m - 1] != 'D')
                ans++;
        }
        cout << ans << '\n';
    }
}