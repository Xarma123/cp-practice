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
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    set<pair<lol, lol>> len, seg;
    for (lol i = 0; i < n; i++)
    {
        lol j = i + 1;
        while (j < n && a[j] == a[i])
            j++;
        len.insert({-(j - i), i});
        seg.insert({i, j - i});
        i = j - 1;
    }
    lol ans = 0;
    while (!len.empty())
    {
        ans++;
        lol i = (*len.begin()).second;
        lol l = (*len.begin()).first;

        len.erase(len.begin());
        seg.erase({i, -l});
        auto it = seg.lower_bound({i, LONG_LONG_MIN});
        if (it != seg.end())
        {
            auto it2 = it;
            if (it2 != seg.begin())
            {
                it2--;
                if (a[(*it2).first] == a[(*it).first])
                {
                    len.erase({-(*it2).second, (*it2).first});
                    len.erase({-(*it).second, (*it).first});
                    lol v = (*it2).second + (*it).second;
                    lol st = (*it2).first;
                    seg.insert({st, v});
                    len.insert({-v, st});
                    seg.erase(it);
                    seg.erase(it2);
                }
            }
        }
    }
    cout << ans;

    return 0;
}