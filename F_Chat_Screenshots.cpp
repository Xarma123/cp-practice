#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        map<lol, lol> ind;
        map<lol, vector<lol>> mp;
        for (lol i = 0; i < k; i++)
        {
            lol a[n];
            for (lol j = 0; j < n; j++)
            {
                cin >> a[j];
            }
            for (lol j = 2; j < n; j++)
            {
                ind[a[j - 1]]++;
                mp[a[j]].push_back(a[j - 1]);
            }
        }
        queue<lol> q;
        for (lol i = 1; i <= n; i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }
        lol ans = 0;
        while (!q.empty())
        {
            ans++;
            lol v = q.front();
            q.pop();
            for (auto e : mp[v])
            {
                if (--ind[e] == 0)
                {
                    q.push(e);
                }
            }
        }
        if (ans == n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
