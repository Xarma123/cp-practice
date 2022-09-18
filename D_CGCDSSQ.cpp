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
    map<lol, lol> f;
    map<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        a[i][t]++;
        if (i - 1 >= 0)
        {
            for (auto j = a[i - 1].begin(); j != a[i - 1].end(); j++)
            {
                a[i][__gcd((*j).first, t)] += (*j).second;
            }
        }
        for (auto j = a[i].begin(); j != a[i].end(); j++)
        {
            f[(*j).first] += (*j).second;
        }
    }

    lol q;
    cin >> q;
    while (q--)
    {
        lol x;
        cin >> x;
        cout << f[x] << endl;
    }

    return 0;
}