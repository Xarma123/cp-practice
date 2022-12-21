#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol solve(string s)
{
    lol ans = 0;
    lol q = 1;
    for (lol i = 1; i < s.size(); i++)
    {
        if (i == 1)
            ans += 9;
        else
        {
            ans += q * 9ll;
            q = q * 10ll;
        }
    }
    ans += q * 1ll * (s[0] - '0' - 1);
    for (lol i = 1; i < s.size() - 1; i++)
    {
        q /= 10ll;
        ans += (s[i] - '0') * 1ll * q;
    }
    if (s[0] <= s.back())
        ans++;
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol l, r;
    cin >> l >> r;
    cout << solve(to_string(r)) - solve(to_string(l - 1));

    return 0;
}