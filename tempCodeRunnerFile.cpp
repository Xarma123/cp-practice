#include <bits/stdc++.h>
#define lol long long
using namespace std;
class sparse
{
public:
    vector<vector<lol>> v;
    lol lg[200001];
    sparse(vector<lol> a)
    {
        lg[1] = 0;
        for (lol i = 2; i < 200001; i++)
        {
            lg[i] = 1 + lg[i / 2];
        }

        lol c = a.size();
        v.resize(c);
        for (lol i = 0; i < c; i++)
        {
            v[i].assign(30, 0);
        }
        for (lol i = 0; i < c; i++)
        {
            v[i][0] = a[i];
        }
        for (lol j = 1; j < 30; j++)
        {
            for (lol i = 0; i + (1ll << j) - 1 < c; i++)
            {
                v[i][j] = min(v[i][j - 1], v[i + (1ll << (j - 1))][j - 1]);
            }
        }
    }
    lol mn(lol l, lol r)
    {
        lol j = lg[r - l + 1];
        return min(v[l][j], v[r - (1ll << j) + 1][j]);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    lol q = 1;
    while (cin >> n)
    {
        cout << "Case " << q << ": ";
        vector<lol> a;
        for (lol i = 0; i < n; i++)
        {
            lol q;
            cin >> q;
            a.push_back(q);
        }
        sparse s(a);
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            lol st = -1, e = i;
            while (st != e - 1)
            {
                lol m = (st + e) / 2;
                if (m == -1)
                {
                    st = m;
                }
                else if (s.mn(m, i) == a[i])
                {
                    e = m;
                }
                else
                    st = m;
            }
            if (e == i)
            {
                ans++;
            }
        }
        cout << ans << '\n';
        q++;
    }

    return 0;
}