#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    bool dp[s.size()][2];
    memset(dp, false, sizeof(dp));
    dp[s.size() - 2][0] = true;
    dp[s.size() - 3][1] = true;
    set<string> q;
    if (s.size() - 5 >= 2)
        q.insert(s.substr(s.size() - 2));
    if (s.size() - 5 >= 3)
        q.insert(s.substr(s.size() - 3));
    for (lol i = s.size() - 4; i > 4; i--)
    {
        if (dp[i + 2][1] || (dp[i + 2][0] && !(s[i] == s[i + 2] && s[i + 1] == s[i + 3])))
        {
            dp[i][0] = true;
        }
        if (dp[i + 3][0] || (dp[i + 3][1] && !(s[i] == s[i + 3] && s[i + 1] == s[i + 4] && s[i + 2] == s[i + 5])))
        {
            dp[i][1] = true;
        }
        string a = "";
        a.push_back(s[i]);
        a.push_back(s[i + 1]);
        if (dp[i][0])
            q.insert(a);
        if (dp[i][1])
        {
            a.push_back(s[i + 2]);
            q.insert(a);
        }
    }
    cout << q.size() << '\n';
    for (auto e : q)
        cout << e << '\n';

    return 0;
}