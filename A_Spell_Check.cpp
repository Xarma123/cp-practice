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
        map<char, lol> mp;
        mp['T'] = 1;
        mp['i'] = 1;
        mp['m'] = 1;
        mp['u'] = 1;
        mp['r'] = 1;
        string s;
        cin >> s;
        lol c = 0;
        for (auto e : s)
        {
            mp[e]--;
            if (mp[e] == 0)
                mp.erase(e);
        }
        if (mp.size() == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}