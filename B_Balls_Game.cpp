#include <bits/stdc++.h>
#define lol long long
using namespace std;

lol solve(lol l, lol r, vector<lol> &c)
{
    c.erase(c.begin() + l, c.begin() + r);

    lol ans = r - l;

    for (lol i = 0; i < c.size(); i++)
    {
        lol j = i + 1;
        while (j < c.size() && c[j] == c[i])
            j++;
        if (j - i >= 3)
        {
            ans += max(ans, solve(i, j, c));
            break;
        }
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k, x;
    cin >> n >> k >> x;
    vector<lol> c(n), c2(n);
    for (lol i = 0; i < n; i++)
    {
        cin >> c[i];
        c2[i] = c[i];
    }
    lol ans = LONG_LONG_MIN;

    for (lol i = 0; i < n; i++)
    {
        if (c[i] == x)
        {
            lol j = i + 1;
            while (j < n && c[j] == x)
                j++;
            if (j - i == 2)
            {
                ans = max(ans, solve(i, j, c));
                c = c2;
            }
            i = j - 1;
        }
    }
    if (ans == LONG_LONG_MIN)
        cout << 0;
    else
        cout << ans;

    return 0;
}