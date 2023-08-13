#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    lol c = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            c++;
    }
    if (c)
    {
        cout << n - c;
    }
    else
    {
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            lol g = a[i];
            for (lol j = i + 1; j < n; j++)
            {
                g = __gcd(g, a[j]);
                if (g == 1)
                {
                    ans = min(ans, j - i + n - 1);
                }
            }
        }
        if (ans == LONG_LONG_MAX)
            ans = -1;
        cout << ans;
    }
}