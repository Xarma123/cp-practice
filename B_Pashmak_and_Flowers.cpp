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
    map<lol, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        lol q;
        cin >> q;
        mp[q]++;
    }
    if ((*mp.rbegin()).first - (*mp.begin()).first == 0)
        cout << 0 << " " << (*mp.rbegin()).second * 1ll * ((*mp.rbegin()).second - 1) / 2;
    else
        cout << (*mp.rbegin()).first - (*mp.begin()).first << " "
             << (*mp.rbegin()).second * 1ll * (*mp.begin()).second;

    return 0;
}