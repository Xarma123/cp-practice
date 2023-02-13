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
    lol a[n];
    lol b[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = 0;
    }
    for (lol i = 0; i < 64; i++)
    {
        lol c = 0;
        for (lol j = 0; j < n; j++)
        {
            if ((a[j] & (1ll << i)))
            {
                c++;
            }
        }
        for (lol j = 0; j < n && c > 0; j++, c--)
        {
            b[j] |= (1ll << i);
        }
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        ans += b[i] * 1ll * b[i];
    }
    cout << ans;

    return 0;
}