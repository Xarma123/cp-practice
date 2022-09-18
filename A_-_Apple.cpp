#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol x, y, n;
    cin >> x >> y >> n;
    lol ans = LONG_LONG_MAX;
    for (lol i = 0; i <= n; i++)
    {
        lol l = n - i;
        ans = min((i * x + (y * (l / 3)) + ((l % 3) * x)), ans);
    }
    cout << ans;

    return 0;
}