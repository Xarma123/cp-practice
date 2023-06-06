#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol cou[200005];
lol sum[200005];
map<lol, vector<lol>> mp;
lol mod = 1e9 + 7;
lol n, k;

lol modInverse(lol A, lol M)
{
    lol m0 = M;
    lol y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1)
    {

        lol q = A / M;
        lol t = M;

        M = A % M, A = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}
void dfs(lol c, lol p)
{

    cou[c] = 1;
    sum[c] = 1;
    for (auto e : mp[c])
    {
        if (e != p)
        {
            dfs(e, c);
            cou[c] += cou[e];
            cou[c] %= mod;
            sum[c] += sum[e] + cou[e];
            sum[c] %= mod;
        }
    }
}
void dfs(lol c, lol p, lol &ans)
{

    ans += ((sum[c] - 1) * 1ll * modInverse((n * 1ll * (n - 1)), mod)) % mod;
    ans %= mod;

    for (auto e : mp[c])
    {
        if (e != p)
        {
            lol a = sum[c] - sum[e] - cou[e] + cou[c] - cou[e];
            lol b = cou[c] - cou[e];
            a = ((a % mod) + mod) % mod;
            b = ((b % mod) + mod) % mod;
            sum[e] += a;
            sum[e] %= mod;
            cou[e] += b;
            cou[e] %= mod;
            dfs(e, c, ans);
            sum[e] -= a;
            sum[e] %= mod;
            sum[e] += mod;
            sum[e] %= mod;
            cou[e] -= b;
            cou[e] %= mod;
            cou[e] += mod;
            cou[e] %= mod;
        }
    }
}
int main()
{
    cin >> n >> k;

    mp.clear();
    for (lol i = 0; i < n - 1; i++)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    if (k == 1 || k == 3)
    {
        cout << 1 << '\n';
    }
    else if (k == 2)
    {
        dfs(1, -1);
        lol ans = 0;
        dfs(1, -1, ans);
        cout << ans << '\n';
    }
}