#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        set<lol> p;
        vector<vector<lol>> v;
        while (n--)
        {
            lol l, r, a, b;
            cin >> l >> r >> a >> b;
            v.push_back({l, r, a, b});
            p.insert(l);
            p.insert(r);
            p.insert(a);
            p.insert(b);
        }

        lol q;
        cin >> q;
        vector<lol> x;
        for (lol i = 0; i < q; i++)
        {
            lol a;
            cin >> a;
            x.push_back(a);
            p.insert(a);
        }
        vector<lol> pt;
        for (auto e : p)
            pt.push_back(e);
        
    }
}