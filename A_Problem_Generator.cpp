#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        map<char, lol> mp;
        for (auto e : s)
        {
            mp[e]++;
        }
        lol ans = 0;
        for (char i = 'A'; i <= 'G'; i++)
        {
            ans += max(0ll, m - mp[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}
