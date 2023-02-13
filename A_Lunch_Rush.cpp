#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol ans = LONG_LONG_MIN;
    while (n--)
    {
        lol f, t;
        cin >> f >> t;
        if (t >= k)
            ans = max(ans, f - (t - k));
        else
            ans = max(ans, f);
    }
    cout << ans;

    return 0;
}