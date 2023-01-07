#include <bits/stdc++.h>
#define lol long long
using namespace std;

lol solve(string &a, lol p, lol c[])
{
    if (p < 0)
    {
        return 1;
    }
    lol ans = 0;
    lol v = c[p];
    lol q = a[p] - '0';
    lol t = (q - v + 10) % 10;
    if (v + t >= 10)
    {
        if (p - 2 < 0)
            return 0;
        c[p - 2] += (v + t) / 10;
        ans += (t + 1) * 1ll * solve(a, p - 1, c);
        c[p - 2] -= (v + t) / 10;
        c[p - 2] += (v + t + 10) / 10;
        ans += (9 - t) * 1ll * solve(a, p - 1, c);
        c[p - 2] -= (v + t + 10) / 10;
    }
    else
    {
        ans += (t + 1) * 1ll * solve(a, p - 1, c);
        if (p - 2 >= 0)
        {
            c[p - 2] += (v + t + 10) / 10;
            ans += (9 - t) * 1ll * solve(a, p - 1, c);
            c[p - 2] -= (v + t + 10) / 10;
        }
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        lol c[s.size()];
        memset(c, 0, sizeof(c));
        cout << solve(s, s.size() - 1, c) - 2 << '\n';
    }

    return 0;
}