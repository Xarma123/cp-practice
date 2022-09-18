#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, lol> mp;
lol ans(string s, lol i)
{
    if (mp.count(i))
        return mp[i];
    if (s.size() == i)
        return 1;
    if (s[i] == '0')
        return 0;
    if (s.size() - i >= 2)
    {
        if (s[i] == '1')
        {
            return ans(s, i + 1) + ans(s, i + 2);
        }
        else if (s[i] == '2')
        {
            if (s[i + 1] <= '6')
                return ans(s, i + 1) + ans(s, i + 2);
        }
    }
    return mp[i]=ans(s, i + 1);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        string s;
        cin >> s;
        if (s == "0")
            break;
        mp.clear();
        if (s.size() == 0)
            cout << 0 << endl;
        else
            cout << ans(s, 0) << endl;
    }

    return 0;
}