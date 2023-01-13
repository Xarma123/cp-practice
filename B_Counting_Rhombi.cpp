#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol w, h;
    cin >> w >> h;
    lol ans = 0;
    for (lol j = 0; j <= h; j++)
    {
        for (lol i = 0; i <= w; i++)
        {
            ans += min(w - i, i) * 1ll * min(j, h - j);
        }
    }
    cout << ans;

    return 0;
}