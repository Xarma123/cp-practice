#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol ncr[5001][5001];
lol m = 998244353;
lol solve(lol a, lol b)
{
    if (a > b)
        swap(a, b);
    lol ans = 0;
    for (lol i = 0; i <= a; i++)
    {
        lol v = ncr[a][i];
        for (lol j = 0; j < i; j++)
        {
            v = (v * 1ll * (b - j)) % m;
        }
        ans = (ans + v) % m;
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, b, c;
    cin >> a >> b >> c;

    for (lol i = 0; i < 5001; i++)
    {
        for (lol j = 0; j < 5001; j++)
        {
            if (i < j)
            {
                ncr[i][j] = 0;
            }
            else if (i == j)
            {
                ncr[i][j] = 1;
            }
            else if (j == 0)
            {
                ncr[i][j] = 1;
            }
            else
                ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % m;
        }
    }
    cout << (((solve(a, b) * 1ll * solve(b, c)) % m) * 1ll * solve(a, c)) % m;

    return 0;
}