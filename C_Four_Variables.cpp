#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol div(lol a)
{
    lol v = 0;
    for (lol i = 1; i * 1ll * i <= a; i++)
    {
        if (a % i == 0)
        {
            v++;
            if (i != (a / i))
                v++;
        }
    }
    return v;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol ans = 0;
    for (lol i = 1; i < n; i++)
    {
        ans += div(i) * 1ll * div(n - i);
    }
    cout << ans;

    return 0;
}