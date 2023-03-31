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
        map<char, lol> mp;
        lol mx = 0;
        string s;
        cin >> s;
        for (lol i = 0; i < 4; i++)
        {
            mp[s[i]]++;
            mx = max(mx, mp[s[i]]);
        }
        if (mx == 4)
            cout << -1 << '\n';
        else if (mx == 3)
            cout << 6 << "\n";
        else
            cout << 4 << '\n';
    }

    return 0;
}