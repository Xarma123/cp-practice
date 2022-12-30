#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<string, set<string>> mp;
map<string, lol> co;
lol a1 = LONG_LONG_MIN, a2 = LONG_LONG_MIN;
pair<lol, lol> dfs(string s)
{

    lol c = 1, f = co[s];
    for (auto e : mp[s])
    {
        pair<lol, lol> q = dfs(e);
        a1 = max(a1, q.first);
        a2 = max(a2, q.second);
        c += q.first;
        f += q.second;
    }

    return {c, f};
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    set<string> vis;
    while (cin >> s)
    {

        string baap = s.substr(0, 1);
        vis.insert(baap);
        lol lev = 0;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == '\\')
            {
                lol j = i + 1;
                while (j < s.size() && s[j] != '\\')
                    j++;
                if (j == s.size())
                {
                    co[baap]++;
                }
                else
                {
                    mp[baap].insert(s.substr(0, 1) + ":" + to_string(lev) + baap + s.substr(i + 1, j - i));
                    baap = s.substr(0, 1) + ":" + to_string(lev) + baap + s.substr(i + 1, j - i);
                }
                i = j - 1;
                lev++;
            }
        }
    }

    for (auto s : vis)
    {
        pair<lol, lol> a = dfs(s);
    }
    cout << a1 - 1 << " " << a2;

    return 0;
}