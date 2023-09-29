#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol solve(lol p[], lol n)
{
    lol ans = 0;
    vector<lol> e, o;
    vector<lol> a;
    for (lol i = 0; i < n; i++)
    {
        if (p[i] == 0)
        {
            lol j = i + 1;
            while (j < n && p[j] == p[i])
            {
                j++;
            }
            if (i - 1 < 0 && j >= n)
            {
                return 1;
            }
            if (i - 1 < 0)
            {
                if (p[j] % 2 == 0)
                    e.push_back(j - i);
                else
                    o.push_back(j - i);
            }
            else if (j == n)
            {
                if (p[i - 1] % 2 == 0)
                    e.push_back(j - i);
                else
                    o.push_back(j - i);
            }
            else if ((p[i - 1] % 2) == (p[j] % 2))
            {
                if (p[i - 1] % 2 == 0)
                    e.push_back(j - i);
                else
                    o.push_back(j - i);
            }

            i = j - 1;
        }
        else
            a.push_back(p[i]);
    }
    for (lol i = 1; i < a.size(); i++)
    {
        if (a[i] % 2 != a[i - 1] % 2)
            ans++;
    }

    bool un[n + 1];
    memset(un, true, sizeof(un));
    for (auto x : a)
        un[x] = false;
    lol ev = 0, od = 0;
    for (lol i = 1; i <= n; i++)
    {
        if (un[i])
        {
            if (i % 2 == 0)
                ev++;
            else
                od++;
        }
    }
    sort(e.begin(), e.end());
    sort(o.begin(), o.end());
    ans += 2ll * e.size();
    ans += 2ll * o.size();
    multiset<pair<lol, lol>> x;
    for (auto y : e)
    {
        x.insert({y, 0});
    }
    for (auto y : o)
    {
        x.insert({y, 1});
    }
    while (!x.empty())
    {
        pair<lol, lol> q = (*x.begin());
        x.erase(x.begin());
        if (q.second == 0)
        {
            if (ev >= q.first)
            {
                ev -= q.first;
                ans -= 2;
            }
        }
        else
        {
            if (od >= q.first)
            {
                od -= q.first;
                ans -= 2;
            }
        }
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol p[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    bool un[n + 1];
    memset(un, true, sizeof(un));
    for (lol i = 0; i < n; i++)
    {
        un[p[i]] = false;
    }
    vector<lol> ev, od;
    for (lol i = 1; i <= n; i++)
    {
        if (un[i])
        {
            if (i % 2 == 0)
                ev.push_back(i);
            else
                od.push_back(i);
        }
    }
    if (p[0] != 0 && p[n - 1] != 0)
    {
        cout << solve(p, n);
    }
    else if (p[0] == 0 && p[n - 1] == 0)
    {

        lol ans = LONG_LONG_MAX;
        // e e
        if (ev.size() >= 2)
        {
            p[0] = ev[0];
            p[n - 1] = ev[1];
            ans = min(ans, solve(p, n));
            p[0] = 0;
            p[n - 1] = 0;
        }
        // e o
        if (ev.size() >= 1 && od.size() >= 1)
        {
            p[0] = ev[0];
            p[n - 1] = od[0];
            ans = min(ans, solve(p, n));
            p[0] = 0;
            p[n - 1] = 0;
        }
        // o e
        if (ev.size() >= 1 && od.size() >= 1)
        {
            p[0] = od[0];
            p[n - 1] = ev[0];
            ans = min(ans, solve(p, n));
            p[0] = 0;
            p[n - 1] = 0;
        }
        // o o
        if (od.size() >= 2)
        {
            p[0] = od[0];
            p[n - 1] = od[1];
            ans = min(ans, solve(p, n));
            p[0] = 0;
            p[n - 1] = 0;
        }
        cout << ans;
    }
    else if (p[0] == 0)
    {
        lol ans = LONG_LONG_MAX;
        if (ev.size())
        {
            p[0] = ev[0];
            ans = min(ans, solve(p, n));
            p[0] = 0;
        }
        if (od.size())
        {
            p[0] = od[0];
            ans = min(ans, solve(p, n));
            p[0] = 0;
        }
        cout << ans;
    }
    else
    {

        lol ans = LONG_LONG_MAX;
        if (ev.size())
        {
            p[n - 1] = ev[0];
            ans = min(ans, solve(p, n));
            p[n - 1] = 0;
        }
        if (od.size())
        {
            p[n - 1] = od[0];
            ans = min(ans, solve(p, n));
            p[n - 1] = 0;
        }
        cout << ans;
    }
}