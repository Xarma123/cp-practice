#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol solve(vector<lol> &a, lol i, lol d)
{
    lol j = i + d - 1;
    lol ans = 0;
    for (lol k = i; k <= j; k++)
    {
        ans += abs(a[k] - a[i + (d / 2)]);
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    lol s = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    lol ans = LONG_LONG_MAX;
    vector<lol> in;
    for (lol i = 0; i < n; i++)
    {
        if (a[i])
            in.push_back(i);
    }
    if (in.size() == 0)
    {
        cout << 0;
        return 0;
    }
    for (lol i = 1; i * 1ll * i <= s; i++)
    {
        if (s % i == 0)
        {
            lol d = i;
            lol cans = 0;
            for (lol j = 0; j < in.size(); j += d)
            {

                cans += solve(in, j, d);
            }
            if (d != 1)
                ans = min(ans, cans);
            d = s / i;
            cans = 0;
            for (lol j = 0; j < in.size(); j += d)
            {

                cans += solve(in, j, d);
            }
            if (d != 1)
                ans = min(ans, cans);
        }
    }

    if (ans == LONG_LONG_MAX)
        ans = -1;
    cout << ans;
}