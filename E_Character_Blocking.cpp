#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol test;
    cin >> test;
    while (test--)
    {
        string s[2];
        cin >> s[0] >> s[1];
        lol t, q;
        cin >> t >> q;
        set<lol> unblock;
        for (lol i = 0; i < s[0].size(); i++)
        {
            if (s[0][i] != s[1][i])
                unblock.insert(i);
        }
        vector<lol> ind[q + 1 + 2ll * t + 5];
        lol st = 0;
        while (q--)
        {
            lol type;
            cin >> type;
            for (auto e : ind[st])
            {
                unblock.insert(e);
            }
            if (type == 1)
            {
                lol i;
                cin >> i;
                i--;
                if (s[0][i] != s[1][i])
                {
                    unblock.erase(i);
                    ind[st + t ].push_back(i);
                }
            }
            else if (type == 2)
            {
                lol f, i, f2, j;
                cin >> f >> i >> f2 >> j;
                f--;
                f2--;
                i--;
                j--;
                if (i != j)
                {
                    if (unblock.count(i))
                        unblock.erase(i);
                    if (unblock.count(j))
                        unblock.erase(j);
                }
                swap(s[f][i], s[f2][j]);
                if (s[0][i] != s[1][i])
                    unblock.insert(i);
                if (s[0][j] != s[1][j])
                    unblock.insert(j);
            }
            else
            {
                if (unblock.size())
                    cout << "NO\n";
                else
                    cout << "YES\n";
            }
            st++;
        }
    }
}