#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol ia[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            ia[a[i] - 1] = i;
        }
        lol b[n];
        lol ib[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            ib[b[i] - 1] = i;
        }
        lol d[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        bool vis[n];
        memset(vis, false, sizeof(vis));
        queue<lol> q;
        set<lol> x;
        for (lol i = 0; i < n; i++)
        {
            if (d[i] != 0 || a[i] == b[i])
            {
                vis[i] = true;
                q.push(i);
                if (a[i] == b[i])
                    d[i] = a[i];
            }
        }
        while (!q.empty())
        {
            lol i = q.front();
            x.insert(d[i]);
            q.pop();
            if (d[i] == a[i])
            {
                if (!vis[ia[b[i] - 1]])
                {
                    vis[ia[b[i] - 1]] = true;
                    q.push(ia[b[i] - 1]);
                    d[ia[b[i] - 1]] = a[ia[b[i] - 1]];
                }
            }
            else
            {
                if (!vis[ib[a[i] - 1]])
                {
                    vis[ib[a[i] - 1]] = true;
                    q.push(ib[a[i] - 1]);
                    d[ib[a[i] - 1]] = b[ib[a[i] - 1]];
                }
            }
        }
        for (lol i = 0; i < n; i++)
        {
            if (x.count(a[i]) && !x.count(b[i]) && !vis[i])
            {
                d[i] = b[i];
                vis[i] = true;
                q.push(i);
            }
            else if (x.count(b[i]) && !x.count(a[i]) && !vis[i])
            {
                d[i] = a[i];
                vis[i] = true;
                q.push(i);
            }
        }
        while (!q.empty())
        {
            lol i = q.front();
            x.insert(d[i]);
            q.pop();
            if (d[i] == a[i])
            {
                if (!vis[ia[b[i] - 1]])
                {
                    vis[ia[b[i] - 1]] = true;
                    q.push(ia[b[i] - 1]);
                    d[ia[b[i] - 1]] = a[ia[b[i] - 1]];
                }
            }
            else
            {
                if (!vis[ib[a[i] - 1]])
                {
                    vis[ib[a[i] - 1]] = true;
                    q.push(ib[a[i] - 1]);
                    d[ib[a[i] - 1]] = b[ib[a[i] - 1]];
                }
            }
        }
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                c++;
                lol j = i;
                while (!vis[j])
                {
                    vis[j] = true;
                    j = ia[b[j] - 1];
                }
            }
        }
        lol r = 1;
        lol m = 1e9 + 7;
        lol v = 2;
        while (c > 0)
        {
            if (c % 2 != 0)
                r = (r * 1ll * v) % m;
            v = (v * 1ll * v) % m;
            c /= 2;
        }
        cout << r << endl;
    }

    return 0;
}