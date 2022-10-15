#include <bits/stdc++.h>
#define lol long long
using namespace std;
string s;
lol dp[100][2][4];
lol solve(lol idx, bool last, lol c)
{
    if (dp[idx][last][c] != -1)
        return dp[idx][last][c];

    if (idx == s.size())
    {
        return 1;
    }
    lol ans = 0;
    lol till = last ? (s[idx] - '0') : 9;
    for (lol i = 0; i <= till; i++)
    {
        lol upc = c;
        if (i)
        {
            upc++;
        }
        if (upc <= 3)
        {
            ans += solve(idx + 1, last && (i == till), upc);
        }
        else
            break;
    }
    return dp[idx][last][c] = ans;
}
map<string, lol> mp;
lol solve(string v)
{
    // memset(dp, -1, sizeof(dp));
    s = v;
    if (mp.count(v))
        return mp[v];
    return mp[v] = solve(0, true, 0);
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
        if (l == r)
        {
            lol c = 0;
            while (l)
            {
                if ((l % 10))
                    c++;
                l /= 10;
            }
            if (c <= 3)
                cout << 1;
            else
                cout << 0;
            cout << endl;
        }
        else
            cout << solve(to_string(r)) - solve(to_string(l - 1)) << endl;
    }

    return 0;
}