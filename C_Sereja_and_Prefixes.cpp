#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol m;
    cin >> m;
    vector<vector<lol>> p;
    lol q = 0;
    while (m--)
    {
        lol t;
        cin >> t;
        if (t == 1)
        {
            lol x;
            cin >> x;
            p.push_back({x, q + 1});
            q++;
        }
        else
        {
            lol l, c;
            cin >> l >> c;
            q += l * 1ll * (c);
            p.push_back({l, c, q});
        }
    }
    lol n;
    cin >> n;
    while (n--)
    {
        lol v;
        cin >> v;
        while (1)
        {

            lol st = -1;
            lol e = p.size() - 1;
            while (st != e - 1)
            {
                lol m = (st + e) / 2;
                if (m == -1)
                {
                    st = m;
                }
                else if (p[m].back() >= v)
                {
                    e = m;
                }
                else
                    st = m;
            }
            if (p[e].size() == 2)
            {
                cout << p[e][0] << ' ';
                break;
            }
            else
            {
                if (e)
                    v -= p[e - 1].back();
                v = v % (p[e][0]);
                if (v == 0)
                    v = p[e][0];
            }
        }
    }

    return 0;
}