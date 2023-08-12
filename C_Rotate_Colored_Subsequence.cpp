#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    map<lol, vector<lol>> mp;
    for (lol i = 0; i < s.size(); i++)
    {
        lol c;
        cin >> c;
        mp[c].push_back(i);
    }
    for (auto e : mp)
    {
        char l = s[e.second.back()];
        for (lol i = e.second.size() - 1; i > 0; i--)
        {
            s[e.second[i]] = s[e.second[i - 1]];
        }
        s[e.second[0]] = l;
    }
    cout << s;
}