#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string s;
    cin >> s;
    set<char> x;
    map<char, lol> mp;
    for (auto c : s)
        x.insert(c);
    lol need = x.size();
    lol ans = s.size();
    lol j = -1;
    for (lol i = 0; i < s.size(); i++)
    {
        if (mp.size() < need)
        {
            while (j + 1 < s.size() && mp.size() != need)
            {
                mp[s[++j]]++;
            }
        }
        if (mp.size() == need)
            ans = min(ans, j - i + 1);
        mp[s[i]]--;
        if (mp[s[i]] == 0)
            mp.erase(s[i]);
    }
    cout << ans;

    return 0;
}