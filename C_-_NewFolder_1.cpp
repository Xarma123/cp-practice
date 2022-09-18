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
    map<string, lol> mp;
    while (n--)
    {
        string s;
        cin >> s;
        cout << s;
        if (mp.count(s))
            cout << "(" << mp[s] << ")";
        cout << endl;
        mp[s]++;
    }

    return 0;
}