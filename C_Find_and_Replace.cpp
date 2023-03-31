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
        lol n;
        cin >> n;
        string s;
        cin >> s;
        map<char, lol> mp;
        bool ans = true;
        for (lol i = 0; i < n; i++)
        {
            if (mp.count(s[i]) && mp[s[i]] != (i % 2))
                ans = false;
            if (!mp.count(s[i]))
                mp[s[i]] = (i % 2);
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}