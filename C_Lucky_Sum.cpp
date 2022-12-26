#include <bits/stdc++.h>
#define lol long long
using namespace std;

lol solve(lol a, string c)
{
    if (a < stoll(c))
        return 0;
    string p = c;
    if (c == "0")
        c = "4";
    else
    {
        lol i;
        for (i = c.size() - 1; i >= 0; i--)
        {
            if (c[i] == '4')
            {
                c[i] = '7';
                break;
            }
        }
        if (i < 0)
            c.push_back('4');
        for (i++; i < c.size(); i++)
        {
            c[i] = '4';
        }
    }
    lol ans = (min(stoll(c), a) - stol(p)) * 1ll * stoll(c);
    return ans + solve(a, c);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol l, r;
    cin >> l >> r;
    cout << solve(r, "0") - solve(l - 1, "0");

    return 0;
}