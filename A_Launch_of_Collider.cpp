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
    string s;
    cin >> s;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol ans = LONG_LONG_MAX;
    for (lol i = 0; i < n; i++)
    {
        if (s[i] == 'R')
        {
            if (i + 1 < n && s[i + 1] == 'L')
            {
                ans = min((a[i + 1] - a[i]) / 2, ans);
            }
        }
        else
        {
            if (i - 1 >= 0 && s[i - 1] == 'R')
            {
                ans = min((a[i] - a[i - 1]) / 2, ans);
            }
        }
    }
    if (ans == LONG_LONG_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}