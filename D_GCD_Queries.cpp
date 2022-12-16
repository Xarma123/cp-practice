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
        lol n;
        cin >> n;
        set<lol> ind;
        for (lol i = 1; i <= n; i++)
        {
            ind.insert(i);
        }
        while (ind.size() > 2)
        {
            map<lol, vector<lol>> mp;
            lol j = (*ind.begin());

            for (auto i : ind)
            {
                if (i == j)
                {
                    continue;
                }
                cout << "? " << i << " " << j << endl;
                lol g;
                cin >> g;
                if (g == -1)
                    exit(0);
                mp[g].push_back(i);
            }
            ind.clear();
            for (auto e : (*mp.rbegin()).second)
                ind.insert(e);
            if (ind.size() == 1)
                ind.insert(j);
        }

        vector<lol> v;
        for (auto e : ind)
            v.push_back(e);

        cout << "! " << v[0] << " " << v[1] << endl;
        lol p;
        cin >> p;
        if (p == -1)
            exit(0);
    }

    return 0;
}