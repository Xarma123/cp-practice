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
    for (lol qqqw = 1; qqqw <= t; qqqw++)
    {
        cout << "Case #" << qqqw << ": ";
        lol mp[26];
        for (lol i = 0; i < 26; i++)
        {
            cin >> mp[i];
        }
        lol n;
        cin >> n;
        set<string> x;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            string sn = "";
            for (auto e : s)
            {
                sn += char(mp[e - 'A'] + '0');
            }
            ans += x.count(sn);
            x.insert(sn);
        }
        if (ans > 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}