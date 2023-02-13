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

    lol mn = LONG_LONG_MAX;
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        lol a, b;
        cin >> a >> b;
        mn = min(mn, b);
        ans += a * 1ll * mn;
    }
    cout << ans;

    return 0;
}