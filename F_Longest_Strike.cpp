#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            lol q;
            cin >> q;
            mp[q]++;
        }
        lol ans = -1;
        lol l = -1;
        lol r = -2;
        lol L = -2;
        lol R = -1;

        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            if ((*i).second >= k)
            {
                if ((*i).first == r + 1)
                {
                    r++;
                }
                else
                {
                    l = (*i).first;
                    r = (*i).first;
                }
            }
            if (r - l >= ans)
            {
                ans = r - l;
                L = l;
                R = r;
            }
        }
        if (ans == -1)
            cout << -1 << endl;
        else
            cout << L << " " << R << endl;
    }

    return 0;
}