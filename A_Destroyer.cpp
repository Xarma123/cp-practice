#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            lol c;
            cin >> c;
            mp[c]++;
        }
        lol last = LONG_LONG_MAX;
        bool ans = true;
        lol last1 = -1;
        for (auto e : mp)
        {
            if (!ans)
                break;
            if (e.first == last1 + 1)
            {
                last1++;
            }
            else
                ans = false;
            if (e.second <= last)
            {
                last = e.second;
            }
            else
                ans = false;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}