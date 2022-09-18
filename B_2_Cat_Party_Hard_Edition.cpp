#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol f[100001], c[100001];
int main()
{
    lol n;
    cin >> n;
    lol ans = 0;
    lol mx = LONG_LONG_MIN;
    for (lol i = 0; i < n; i++)
    {
        lol u;
        cin >> u;
        c[f[u]]--;
        f[u]++;
        c[f[u]]++;
        mx = max(mx, f[u]);
        if (c[1] == i + 1) // all 1
            ans = i + 1;
        else if (f[u] == i + 1) // only 1
            ans = i + 1;
        else if (c[mx] == 1 && c[mx - 1] * (mx - 1) == i + 1 - mx)
            ans = i + 1;
        else if (c[mx] * mx == i)
            ans = i + 1;
    }
    cout << ans;

    return 0;
}