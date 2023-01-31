#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol w, m;
    cin >> w >> m;
    if (w == 2 || w == 3)
        cout << "YES";
    else
    {
        lol p = 1;
        vector<lol> v;
        while (p <= m)
        {
            v.push_back(p);
            p = p * 1ll * w;
        }
        v.push_back(p);
        bool ans = false;
        set<lol> x;
        for (lol i = 0; i < (1ll << (v.size())); i++)
        {
            lol l = 0;
            for (lol j = 0; j < v.size(); j++)
            {
                if ((i & (1ll << j)))
                {
                    l += v[j];
                }
            }
            x.insert(l);
        }
        for (auto e : x)
        {
            ans |= (x.find(e - m) != x.end());
        }
        if (ans)
            cout << "YES";
        else
            cout << "NO";
    }

    return 0;
}