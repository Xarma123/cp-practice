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
    string ans = s;
    for (lol i = 0; i < 10; i++)
    {
        for (lol j = 0; j < s.size(); j++)
        {
            s[j] = char(((s[j] - '0' + (i > 0)) % 10) + '0');
        }
        string s2 = s + s;
        for (lol i = 0; i < s.size(); i++)
        {
            ans = min(ans, s2.substr(i, s.size()));
        }
    }
    cout << ans;

    return 0;
}