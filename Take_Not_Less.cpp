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
        map<lol, lol> mp;
        while (n--)
        {
            lol v;
            cin >> v;
            mp[v]++;
        }
        bool ev = true;
        for (auto e : mp)
        {
            if (e.second % 2)
                ev = false;
        }
        if (ev)
            cout << "Zenyk" << '\n';
        else
            cout << "Marichka" << '\n';
    }

    return 0;
}