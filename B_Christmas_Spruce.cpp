#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool ans = true;
lol h(lol r, map<lol, vector<lol>> &mp)
{
    lol c = 0;
    lol x = 0;
    for (lol i = 0; i < mp[r].size(); i++)
    {
        lol q = h(mp[r][i], mp);
        if (q == 1)
            c++;
        x = max(x, q);
    }
    if (mp[r].size() > 0 && c < 3)
        ans = false;
    return 1 + x;
}
int main()
{
    lol n;
    cin >> n;
    map<lol, vector<lol>> mp;
    for (lol i = 2; i < n + 1; i++)
    {
        lol t;
        cin >> t;
        mp[t].push_back(i);
    }
    h(1, mp);
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}