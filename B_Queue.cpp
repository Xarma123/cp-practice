#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    pair<lol, lol> a[n];
    lol ans[n];
    memset(ans, -1, sizeof(ans));
    map<lol, lol> f, b;
    set<lol> used;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        f[a[i].first] = a[i].second;
        b[a[i].second] = a[i].first;
        if (a[i].first == 0)
        {
            ans[1] = a[i].second;
            used.insert(a[i].second);
        }
        if (a[i].second == 0)
        {
            ans[n - 2] = a[i].first;
            used.insert(a[i].first);
        }
    }
    for (lol i = 0; i < n; i++)
    {
        if (ans[i] != -1)
        {
            if (f.count(ans[i]))
            {
                if (f[ans[i]] != 0)
                {
                    ans[i + 2] = f[ans[i]];
                    used.insert(ans[i + 2]);
                }
            }
            if (b.count(ans[i]))
            {
                if (b[ans[i]] != 0)
                {
                    ans[i - 2] = b[ans[i]];
                    used.insert(ans[i - 2]);
                }
            }
        }
    }
    for (lol i = n - 1; i >= 0; i--)
    {
        if (ans[i] != -1)
        {
            if (f.count(ans[i]))
            {
                if (f[ans[i]] != 0)
                {
                    ans[i + 2] = f[ans[i]];
                    used.insert(ans[i + 2]);
                }
            }
            if (b.count(ans[i]))
            {
                if (b[ans[i]] != 0)
                {
                    ans[i - 2] = b[ans[i]];
                    used.insert(ans[i - 2]);
                }
            }
        }
    }
    if (n % 2)
    {
        lol q;
        for (lol i = 0; i < n; i++)
        {
            if (!used.count(a[i].first) && a[i].first != 0)
            {
                q = a[i].first;
                while (f.count(q))
                {
                    q = f[q];
                    cout << q << endl;
                }
            }
        }
        for (lol i = n - 1; i >= 0; i--)
        {
            if (ans[i] == -1)
            {
                ans[i] = q;
                q = b[q];
            }
        }
    }
    for (lol i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}