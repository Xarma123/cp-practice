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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            a[i] = max(i - (a[i] - 1), 0ll);
        }
        lol st[n+1][26];
        for (lol i = 0; i <= n; i++)
        {
            for (lol j = 0; j < 25; j++)
            {
                st[i][j] = LONG_LONG_MIN;
            }
        }
        lol lg[n + 1];
        lg[1] = 0;
        for (lol i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        for (lol i = 0; i < n; i++)
            st[i][0] = a[i];

        for (lol j = 1; j <= 25; j++)
            for (lol i = 0; i + (1 << j) <= n; i++)
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

        for (lol i = n - 1; i >= 0; i--)
        {
            if (a[i] == i)
                continue;
            lol l = a[i];
            lol r = i;
            lol j = lg[r - l + 1];
            lol v = max(st[l][j], st[r - (1 << j) + 1][j]);
            if (v == LONG_LONG_MIN)
                continue;
           
            ans += i - v;
        }

        ans += n;
        cout << ans << endl;
    }

    return 0;
}