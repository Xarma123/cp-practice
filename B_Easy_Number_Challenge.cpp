#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, lol> mp;
lol d(lol a)
{
    if (mp.count(a))
        return mp[a];
    lol ans = 0;
    for (lol i = 1; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            ans++;
            ans %= (1 << 30);
            if (a / i != i)
            {
                ans++;
                ans %= (1 << 30);
            }
        }
    }
    return mp[a] = ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, b, c;
    cin >> a >> b >> c;
    lol ans = 0;
    for (lol i = 1; i <= a; i++)
    {
        for (lol j = 1; j <= b; j++)
        {
            for (lol k = 1; k <= c; k++)
            {
                ans += d(i * j * k);
                ans %= (1 << 30);
            }
        }
    }
    cout << ans;

    return 0;
}