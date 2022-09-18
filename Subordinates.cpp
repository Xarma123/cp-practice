#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
map<lol, lol> a;
lol ans(lol x)
{
    lol s = 0;
    for (lol i = 0; i < mp[x].size(); i++)
    {
        s += ans(mp[x][i]);
    }
    a[x] = s;

    return s + 1;
}
int main()
{
    lol n;
    cin >> n;
    lol t;
    for (lol i = 1; i < n; i++)
    {
        cin >> t;
        mp[t].push_back(i + 1);
    }
    ans(1);
    for (lol i = 0; i < n; i++)
    {
        cout << a[i + 1] << " ";
    }

    return 0;
}