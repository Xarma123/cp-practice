#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol ans = 0;
lol h, n;
bool dfs(lol l, lol r, bool rt)
{

    if (n > r || n < l)
    {
        ans += 2 * 1ll * (r - l + 1) - 1;
        return false;
    }

    ans++;
    if (l == r && n == l)
        return true;
    if (rt)
    {
        if (dfs((l + r) / 2 + 1, r, !rt))
        {
            return true;
        }
        dfs(l, (l + r) / 2, rt);
    }
    else
    {
        if (dfs(l, (l + r) / 2, !rt))
        {
            return true;
        }
        dfs((l + r) / 2 + 1, r, rt);
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> n;
    dfs(1ll, (1ll << h), false);
    cout << ans - 1;

    return 0;
}