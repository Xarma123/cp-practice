#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n, k, d;
lol m = 1e9 + 7;
map<lol, lol> m1, m2;
lol solve(lol n)
{
    if (n == 0)
        return 1;
    if (m1.count(n))
        return m1[n];
    lol ans = 0;
    for (lol i = 1; i <= k; i++)
    {
        if (n >= i)
        {
            ans += solve(n - i);
            ans %= m;
        }
    }
    return m1[n] = ans;
}
lol solve2(lol n)
{
    if (n == 0)
        return 1;
    if (m2.count(n))
        return m2[n];
    lol ans = 0;
    for (lol i = 1; i < d; i++)
    {

        if (n >= i)
        {
            ans += solve2(n - i);
            ans %= m;
        }
    }

    return m2[n] = ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k >> d;
    cout << ((solve(n) - solve2(n))%m+m)%m << endl;
    return 0;
}
