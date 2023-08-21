#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        set<pair<lol, lol>> x;
        x.insert({-n, 0});
        lol ans[n];
        lol c = 1;
        while (!x.empty())
        {
            pair<lol, lol> a = (*x.begin());
            x.erase(x.begin());
            lol l = -a.first;
            lol i = a.second;
            if (l % 2 == 0)
            {
                ans[l / 2 - 1 + i] = c++;
                if ((l / 2) - 1 > 0)
                {
                    x.insert({-((l / 2) - 1), i});
                }
                if (l - l / 2 > 0)
                {
                    x.insert({-(l - l / 2), l / 2 + i});
                }
            }
            else
            {
                ans[l / 2 + i] = c++;
                if (l / 2 > 0)
                {
                    x.insert({-(l / 2), i});
                }
                if (l - l / 2 - 1 > 0)
                {
                    x.insert({-(l - l / 2 - 1), l / 2 + i + 1});
                }
            }
        }
        for (lol i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}