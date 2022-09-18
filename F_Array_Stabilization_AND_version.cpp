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
        lol n, d;
        cin >> n >> d;
        lol a[n];
        bool vis[n];
        queue<lol> q;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
            {
                vis[i] = true;
                q.push(i);
            }
            else
                vis[i] = false;
        }
        lol ans = -1;
        while (!q.empty())
        {
            ans++;
            lol c = q.size();
            while (c--)
            {
                lol i = q.front();
                q.pop();
                lol j = (i + d) % n;
                if (!vis[j])
                {
                    vis[j] = true;
                    q.push(j);
                }
            }
        }
        bool f = true;
        for (auto e : vis)
            f &= e;
        if (!f)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}