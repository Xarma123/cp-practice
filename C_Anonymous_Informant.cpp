#include <bits/stdc++.h>
using namespace std;
#define lol long long
map<lol, vector<lol>> mp;
lol dfs(lol c, bool vis[], bool stack[])
{

    vis[c] = true;
    stack[c] = true;
    lol mx = 0;
    for (auto e : mp[c])
    {
        if (!vis[e])
        {
            mx = max(mx, dfs(e, vis, stack));
        }
        else if (stack[e])
        {
            return LONG_LONG_MAX;
        }
    }
    stack[c] = false;
    if (mx == LONG_LONG_MAX)
        return mx;
    if (mp[c].size())
        return mx + 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        mp.clear();
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {

            if (a[i] <= n)
            {
                if (a[i] <= i + 1)
                {
                    mp[((i + 1) % n)].push_back((i + 1 - a[i]));
                }
                else
                {

                    mp[((n + i + 1) % n)].push_back((n - (a[i] - i - 1)));
                }
            }
        }
        bool vis[n], stack[n];
        memset(vis, false, sizeof(vis));
        memset(stack, false, sizeof(stack));
        lol v = dfs(0, vis, stack);
       
        if (v >= k)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
