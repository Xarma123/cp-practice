#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol v1, v2;
    cin >> v1 >> v2;
    lol t, d;
    cin >> t >> d;
    lol a[t];
    a[0] = v1;
    a[t - 1] = v2;
    lol ans = v1 + v2;
    for (lol i = 1; i < t - 1; i++)
    {
        a[i] = min((t - 1 - i) * 1ll * d + v2, a[i - 1] + d);
        ans += a[i];
    }
    cout << ans;

    return 0;
}