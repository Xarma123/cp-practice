#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    lol f[26];
    memset(f, 0, sizeof(f));
    map<string, lol> mp;
    lol ans = 0;
    for (lol i = 0; i < s.size(); i++)
    {

        for (lol j = 0; j < 26; j++)
        {
            string a = "";
            a += char('a' + j);
            a += s[i];
            mp[a] += f[j];
            ans = max(ans, mp[a]);
        }
        f[s[i] - 'a']++;
        ans = max(ans, f[s[i] - 'a']);
    }
    cout << ans;
}