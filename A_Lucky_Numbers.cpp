#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol solve(lol a)
{
    string x = to_string(a);
    lol mn = 11;
    lol mx = -1;
    for (auto e : x)
    {
        mn = min(mn, (long long)(e - '0'));
        mx = max(mx, (long long)(e - '0'));
    }
    return mx - mn;
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
        lol l, r;
        cin >> l >> r;
        lol ans = LONG_LONG_MIN;
        lol q = l;
        for (lol i = l; i <= r && i <= l + 200; i++)
        {
            lol v = solve(i);
            if (v > ans)
            {
                q = i;
                ans = v;
            }
        }
        cout << q << '\n';
    }

    return 0;
}