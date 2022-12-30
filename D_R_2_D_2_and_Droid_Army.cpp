#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol lg[100005];
class sparse
{
public:
    vector<vector<lol>> v;
    sparse(vector<lol> a)
    {
        v.resize(a.size());
        for (lol i = 0; i < a.size(); i++)
        {
            v[i].assign(30, 0);
        }
        for (lol j = 0; j < 30; j++)
        {
            for (lol i = 0; i + (1ll << j) - 1 < a.size(); i++)
            {
                if (j == 0)
                    v[i][j] = a[i];
                else
                    v[i][j] = max(v[i][j - 1], v[i + (1ll << (j - 1))][j - 1]);
            }
        }
    }
    lol mn(lol l, lol r)
    {
        lol j = lg[r - l + 1];
        return max(v[l][j], v[r - (1ll << j) + 1][j]);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (lol i = 1; i < 100005; i++)
    {
        if (i == 1)
            lg[i] = 0;
        else
            lg[i] = lg[i / 2] + 1;
    }

    lol n, m, k;
    cin >> n >> m >> k;
    vector<vector<lol>> v(m);
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            lol q;
            cin >> q;
            v[j].push_back(q);
        }
    }
    vector<sparse> q;
    for (lol j = 0; j < m; j++)
    {
        sparse s(v[j]);
        q.push_back(s);
    }

    lol st = 0, e = n + 1;
    while (st != e - 1)
    {
        lol md = (st + e) / 2;
        if (md == 0)
        {
            st = md;
        }
        else if (md == n + 1)
            e = md;
        else
        {
            lol c = LONG_LONG_MAX;
            for (lol i = 0; i + md - 1 < n; i++)
            {
                lol c1 = 0;
                for (lol j = 0; j < m; j++)
                {
                    c1 += q[j].mn(i, i + md - 1);
                }
                c = min(c, c1);
            }
            if (c <= k)
            {
                st = md;
            }
            else
                e = md;
        }
    }
    if (st == 0)
    {
        for (lol i = 0; i < m; i++)
        {
            cout << 0 << " ";
        }
    }
    else
    {

        lol c = LONG_LONG_MAX;
        for (lol i = 0; i + st - 1 < n; i++)
        {
            lol c1 = 0;
            for (lol j = 0; j < m; j++)
            {
                c1 += q[j].mn(i, i + st - 1);
            }
            c = min(c, c1);
        }

        lol ans[m];
        memset(ans, 0, sizeof(ans));
        for (lol i = 0; i + st - 1 < n; i++)
        {
            lol c1 = 0;
            for (lol j = 0; j < m; j++)
            {
                c1 += q[j].mn(i, i + st - 1);
            }
            if (c1 == c)
            {
                for (lol j = 0; j < m; j++)
                {
                    ans[j] = q[j].mn(i, i + st - 1);
                }
                break;
            }
        }
        for (lol i = 0; i < m; i++)
        {
            cout << ans[i] << " ";
        }
    }

    return 0;
}