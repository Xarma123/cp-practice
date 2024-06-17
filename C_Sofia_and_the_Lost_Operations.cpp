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
        lol n;
        cin >> n;
        lol a[n], b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        lol m;
        cin >> m;
        lol d[m];
        map<lol, lol> mp;
        for (lol i = 0; i < m; i++)
        {
            cin >> d[i];
            mp[d[i]]++;
        }
        bool c = false;
        set<lol> w;
        for (lol i = 0; i < n; i++)
        {
            w.insert(a[i]);
            if (a[i] != b[i])
            {
                c = true;
                if (--mp[b[i]] == 0)
                {
                    mp.erase(b[i]);
                }
            }
        }
        bool ans = true;

        for (auto e : mp)
        {
            if (e.second < 0)
            {
                ans = false;
            }
            else if (e.second > 0)
            {
                if (c)
                    continue;
                else
                {
                    if (w.count(e.first))
                    {
                        c = true;
                    }
                }
            }
        }
        if (ans && c)
        {
            ans = false;
            for (lol i = 0; i < n; i++)
            {
                if (b[i] == d[m - 1])
                {
                    ans = true;
                }
            }
            if (ans)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
            cout << "NO\n";
    }

    return 0;
}
