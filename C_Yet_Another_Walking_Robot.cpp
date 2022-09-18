#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string s;
        cin >> s;
        lol x = 0, y = 0;
        map<pair<lol, lol>, lol> mp;
        mp[make_pair(x, y)] = -1;
        lol ans = LONG_LONG_MAX;
        lol l, r;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == 'L')
                x--;
            else if (s[i] == 'R')
                x++;
            else if (s[i] == 'U')
                y++;
            else
                y--;
            if (mp.count(make_pair(x, y)))
            {
                if (ans > i - mp[make_pair(x, y)])
                {
                    r = i + 1;
                    l = mp[make_pair(x, y)]+2;
                    ans = r - l + 1;
                }
            }
            mp[make_pair(x, y)] = i;
        }
        if (ans == LONG_LONG_MAX)
            cout << -1 << endl;
        else
            cout << l <<" "<<r<< endl;
    }

    return 0;
}