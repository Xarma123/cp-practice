#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    map<string, set<lol>> mp;
    for (lol i = 0; i < n; i++)
    {
        lol c;
        cin >> c;
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        mp[s].insert(c);
    }
    lol ans = LONG_LONG_MAX;
    if (!mp["ABC"].empty())
        ans = min(ans, (*mp["ABC"].begin()));
    if (!mp["AB"].empty())
    {
        lol c1 = (*mp["AB"].begin());
        if (!mp["C"].empty())
        {
            ans = min(ans, c1 + (*mp["C"].begin()));
        }
        if (!mp["BC"].empty())
        {
            ans = min(ans, c1 + (*mp["BC"].begin()));
        }
        if (!mp["AC"].empty())
        {
            ans = min(ans, c1 + (*mp["AC"].begin()));
        }
    }
    if (!mp["BC"].empty())
    {
        lol c1 = (*mp["BC"].begin());
        if (!mp["A"].empty())
        {
            ans = min(ans, c1 + (*mp["A"].begin()));
        }
        if (!mp["AC"].empty())
        {
            ans = min(ans, c1 + (*mp["AC"].begin()));
        }
        if (!mp["AB"].empty())
        {
            ans = min(ans, c1 + (*mp["AB"].begin()));
        }
    }
    if (!mp["AC"].empty())
    {
        lol c1 = (*mp["AC"].begin());
        if (!mp["B"].empty())
        {
            ans = min(ans, c1 + (*mp["B"].begin()));
        }
        if (!mp["AB"].empty())
        {
            ans = min(ans, c1 + (*mp["AB"].begin()));
        }
        if (!mp["BC"].empty())
        {
            ans = min(ans, c1 + (*mp["BC"].begin()));
        }
    }
    if (!mp["C"].empty() && !mp["B"].empty() && !mp["A"].empty())
    {
        ans = min(ans, (*mp["A"].begin()) + (*mp["B"].begin()) + (*mp["C"].begin()));
    }
    if (ans != LONG_LONG_MAX)
        cout << ans;
    else
        cout << -1;

    return 0;
}