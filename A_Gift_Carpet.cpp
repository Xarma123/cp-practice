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
        string s = "vika";
        lol p = 0;
        for (lol j = 0; j < m && p < 4; j++)
        {
            for (lol i = 0; i < n && p < 4; i++)
            {
                if (a[i][j] == s[p])
                {
                    p++;
                    break;
                }
            }
        }
        if (p < 4)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}