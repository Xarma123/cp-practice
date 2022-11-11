#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol cal(lol p)
{
    lol sum = 0;
    lol x = p;
    while (p)
        sum += p % 10, p /= 10;
    return x * 1ll * (x + sum);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol p = sqrtl(n);
    lol ans = -1;
    lol v = (sqrtl(81ll * 81ll + 4 * 1ll * n) - 81ll) / 2;
    while (p >= v)
    {

        if (cal(p) == n)
            ans = p;
        p--;
    }
    cout << ans;

    return 0;
}