#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    bool ans[n];
    for (lol i = 0; i < n; i++)
    {
        ans[i] = false;
    }

    set<lol> mp;
    for (lol i = 0; i < n; i++)
    {
        if (mp.count(a[i].first))
        {
            ans[i] = true;
        }

        mp.insert(a[i].second);
    }
    mp.clear();
    for (lol i = n - 1; i >= 0; i--)
    {
        if (mp.count(a[i].first))
        {
            ans[i] = true;
        }

        mp.insert(a[i].second);
    }
    lol anss = 0;
    for (lol i = 0; i < n; i++)
    {
        if (ans[i] == false)
        {
            anss++;
        }
    }
    cout << anss;
    return 0;
}