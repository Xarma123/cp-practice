#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    map<lol, lol> mpx;
    map<lol, lol> mpy;
    map<pair<lol, lol>, lol> mpp;
    while (n--)
    {
        lol x, y;
        cin >> x >> y;
        mpx[x]++;
        mpy[y]++;
        mpp[make_pair(x, y)]++;
    }
    lol ans = 0;
    for (auto i = mpx.begin(); i != mpx.end(); i++)
    {
        ans += (*i).second * ((*i).second - 1) / 2;
    }
    for (auto i = mpy.begin(); i != mpy.end(); i++)
    {
        ans += (*i).second * ((*i).second - 1) / 2;
    }
    for (auto i = mpp.begin(); i != mpp.end(); i++)
    {
        ans -= (*i).second * ((*i).second - 1) / 2;
    }
    cout << ans;

    return 0;
}