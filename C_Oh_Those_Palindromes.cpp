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
    map<char, lol> mp;
    for (auto c : s)
        mp[c]++;
    lol ans = 0;
    for (auto e : mp)
    {
        for (lol i = 0; i < e.second; i++)
        {
            cout << e.first;
        }
    }

    return 0;
}