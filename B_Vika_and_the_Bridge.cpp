#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol a[n];
        map<lol, vector<lol>> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]].push_back(i + 1);
        }
        lol ans = LONG_LONG_MAX;
        for (auto e : mp)
        {
            vector<lol> jump;
            lol l = 0;
            for (auto x : e.second)
            {
                jump.push_back(x - l - 1);
                l = x;
            }
            jump.push_back(n - l);
            sort(jump.begin(), jump.end());
            lol v = jump.back();
            jump.pop_back();
            v = v - (v + 1) / 2;
            jump.push_back(v);
            sort(jump.begin(), jump.end());
            ans = min(ans, jump.back());
        }
        cout << ans << '\n';
    }
}