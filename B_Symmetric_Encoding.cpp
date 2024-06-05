#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string s;
        cin >> s;
        set<char> x;
        for (auto e : s)
        {
            x.insert(e);
        }
        vector<char> a;
        for (auto e : x)
        {
            a.push_back(e);
        }
        map<char, char> mp;
        for (lol i = 0; i < a.size(); i++)
        {
            mp[a[i]] = a[a.size() - i - 1];
            mp[a[a.size() - i - 1]] = a[i];
        }
        for (auto e : s)
        {
            cout << mp[e];
        }
        cout << '\n';
    }

    return 0;
}
