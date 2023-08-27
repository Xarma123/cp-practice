#include <bits/stdc++.h>
using namespace std;
#define lol long long

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack<lol> x;
    x.push(-1);

    lol pvg[n];
    for (lol i = 0; i < n; i++)
    {
        while (x.top() != -1 && a[x.top()] < a[i])
        {
            x.pop();
        }
        pvg[i] = x.top();
        x.push(i);
    }
    while (x.top() != -1)
    {
        x.pop();
    }

    lol pv[n];
    for (lol i = 0; i < n; i++)
    {
        while (x.top() != -1 && a[x.top()] > a[i])
        {

            x.pop();
        }
        pv[i] = x.top();
        x.push(i);
    }
    while (x.top() != -1)
    {
        x.pop();
    }

    lol nxg[n];

    for (lol i = n - 1; i >= 0; i--)
    {
        while (x.top() != -1 && a[x.top()] < a[i])
        {
            x.pop();
        }
        nxg[i] = x.top();
        x.push(i);
    }
    while (x.top() != -1)
    {

        x.pop();
    }

    lol nx[n];
    for (lol i = n - 1; i >= 0; i--)
    {
        while (x.top() != -1 && a[x.top()] > a[i])
        {
            x.pop();
        }
        nx[i] = x.top();
        x.push(i);
    }
    while (x.top() != -1)
    {
        x.pop();
    }

    map<lol, vector<lol>> mp;
    for (lol i = 0; i < n; i++)
    {
        if (pv[i] != -1)
            mp[pv[i] + 1].push_back(i + 1);
        if (pvg[i] != -1)
            mp[pvg[i] + 1].push_back(i + 1);
        if (nx[i] != -1)
            mp[i + 1].push_back(nx[i] + 1);
        if (nxg[i] != -1)
            mp[i + 1].push_back(nxg[i] + 1);
        if (i + 2 <= n)
            mp[i + 1].push_back(i + 2);
        if (i > 0)
            mp[i + 1].push_back(i);
    }
    lol d[n + 1];
    d[1] = 0;
    for (lol i = 2; i <= n; i++)
    {
        d[i] = LONG_LONG_MAX;
    }
    for (lol i = 1; i <= n; i++)
    {
        for (auto e : mp[i])
        {
            d[e] = min(d[e], d[i] + 1);
        }
    }
    cout << d[n];
}