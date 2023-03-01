#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<char, set<char>> mp;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        mp.clear();
        lol n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        lol i;
        for (i = 0; i < n; i++)
        {
            if (a[i] > b[i])
                break;
            else if (a[i] < b[i])
            {
                mp[a[i]].insert(b[i]);
            }
        }
        if (i == n)
        {
            lol ans = 0;
            for (auto e : mp)
            {
                for (auto c : e.second)
                {
                    if (c == (*e.second.begin()))
                        continue;
                    mp[(*e.second.begin())].insert(c);
                }
                ans++;
            }
            cout << ans << '\n';
        }
        else
            cout << -1 << '\n';
    }

    return 0;
}