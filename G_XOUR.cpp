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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<lol, vector<lol>> ind, val;
        set<lol> all;
        for (lol i = 0; i < n; i++)
        {
            lol v = ((~(3ll)) & a[i]);
            all.insert(v);
            ind[v].push_back(i);
            val[v].push_back(a[i]);
        }
        for (auto e : val)
        {
            sort(val[e.first].begin(), val[e.first].end());
        }
        lol b[n];
        for (auto e : all)
        {
            lol sz = ind[e].size();
            for (lol i = 0; i < sz; i++)
            {
                b[ind[e][i]] = val[e][i];
            }
        }
        for (lol i = 0; i < n; i++)
        {
            cout << b[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
