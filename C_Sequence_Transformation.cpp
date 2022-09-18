#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        vector<lol> x;
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            lol q;
            cin >> q;
            if (x.size() == 0)
            {
                x.push_back(q);
                mp[q]++;
            }
            else if (x.back() != q)
            {
                x.push_back(q);
                mp[q]++;
            }
        }
        lol ans = LONG_LONG_MAX;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {

            ((*i).second)++;
        }

        mp[x[0]]--;
        mp[x[x.size() - 1]]--;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {

            ans = min(((*i).second), ans);
        }
        cout << ans << endl;
    }

    return 0;
}