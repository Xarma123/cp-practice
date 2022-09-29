#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, c;
        cin >> n >> c;

        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            lol q;
            cin >> q;
            mp[q]++;
        }
        lol ans = 0;
        for (auto e : mp)
        {
            if (e.second > c)
            {
                ans += c;
            }
            else
                ans += e.second;
        }
        cout << ans << endl;
    }

    return 0;
}