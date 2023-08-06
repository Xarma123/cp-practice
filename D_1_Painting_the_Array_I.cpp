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
    map<lol, set<lol>> mp;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]].insert(i);
        mp[a[i]].insert(n);
    }
    lol ans = 0;
    vector<lol> b, c;
    b.push_back(0);
    c.push_back(0);
    for (lol i = 0; i < n; i++)
    {
        if (c.back() == a[i] && b.back() != a[i])
        {
            b.push_back(a[i]);
        }
        else if (b.back() == a[i] && c.back() != a[i])
        {
            c.push_back(a[i]);
        }
        else if (c.back() == a[i] && b.back() == a[i])
        {
            c.push_back(a[i]);
        }
        else
        {
            if ((*mp[b.back()].begin()) <= (*mp[c.back()].begin()))
                b.push_back(a[i]);
            else
                c.push_back(a[i]);
        }
        mp[a[i]].erase(i);
    }
    for (lol i = 1; i < b.size(); i++)
    {
        lol j = i + 1;
        while (j < b.size() && b[j] == b[i])
            j++;
        ans++;
        i = j - 1;
    }
    for (lol i = 1; i < c.size(); i++)
    {
        lol j = i + 1;
        while (j < c.size() && c[j] == c[i])
            j++;
        ans++;
        i = j - 1;
    }

    cout << ans << '\n';
}