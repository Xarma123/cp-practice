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
    lol mxn = 1, f = 0;
    map<char, lol> mp;
    for (auto c : s)
    {
        mp[c]++;
        if (mp[c] == f)
        {
            mxn++;
        }
        else if (mp[c] > f)
        {
            f = mp[c];
            mxn = 1;
        }
    }
    lol m = 1e9 + 7;
    lol ans = 1;
    while (n)
    {
        if (n % 2)
            ans = (ans * 1ll * mxn) % m;
        n /= 2;
        mxn = (mxn * 1ll * mxn) % m;
    }
    cout << ans;

    return 0;
}