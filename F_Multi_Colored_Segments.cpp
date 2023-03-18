#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segtree
{
public:
    vector<lol> seg;
    lol n;
    segtree(lol c)
    {
        n = 1;
        while (n < c)
            n = n * 2ll;
        seg.assign(2ll * n, -1e10);
    }
    void reset()
    {
        for (lol i = 0; i < 2ll * n; i++)
        {
            seg[i] = -1e10;
        }
    }
    void set(lol i, lol v, lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            seg[x] = v;
            return;
        }
        lol m = (lx + rx) / 2;
        if (i < m)
            set(i, v, x * 2ll + 1, lx, m);
        else
            set(i, v, 2ll * x + 2, m, rx);
        seg[x] = max(seg[2ll * x + 1], seg[2ll * x + 2]);
    }
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, n);
    }
};
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
        lol ans[n];
        for (lol i = 0; i < n; i++)
            ans[i] = LONG_LONG_MAX;
        vector<pair<lol, vector<lol>>> seg(n);
        for (lol i = 0; i < n; i++)
        {
            lol l, r, c;
            cin >> l >> r >> c;
            seg[i] = {l, {r, c, i}};
        }
        sort(seg.begin(), seg.end());
        lol c[n + 1];
        segtree s(n + 1);
        for (lol i = 0; i < n + 1; i++)
        {
            c[i] = -1e10;
        }
        for (lol i = 0; i < n; i++)
        {
            s.set(seg[i].second[1], -1e10);
            lol mx1 = s.seg[0];
            if (mx1 <= seg[i].first)
            {
                ans[seg[i].second[2]] = min(ans[seg[i].second[2]], seg[i].first - mx1);
            }
            else
            {
                ans[seg[i].second[2]] = 0;
            }
            c[seg[i].second[1]] = max(c[seg[i].second[1]], seg[i].second[0]);
            s.set(seg[i].second[1], c[seg[i].second[1]]);
        }
        s.reset();
        for (lol i = 0; i < n + 1; i++)
        {
            c[i] = -1e10;
        }
        for (lol i = n - 1; i >= 0; i--)
        {
            s.set(seg[i].second[1], -1e10);
            lol mx1 = s.seg[0];
            if (seg[i].second[0] >= -mx1)
            {
                ans[seg[i].second[2]] = 0;
            }
            c[seg[i].second[1]] = max(c[seg[i].second[1]], -seg[i].second[0]);
            s.set(seg[i].second[1], c[seg[i].second[1]]);
        }
        for (lol i = 0; i < n; i++)
        {
            seg[i].first *= -1;
            seg[i].second[0] *= -1;
            swap(seg[i].first, seg[i].second[0]);
        }
        sort(seg.begin(), seg.end());
        s.reset();
        for (lol i = 0; i < n + 1; i++)
        {
            c[i] = -1e10;
        }
        for (lol i = 0; i < n; i++)
        {
            lol q = c[seg[i].second[1]];
            s.set(seg[i].second[1], -1e10);
            lol mx1 = s.seg[0];
            if (mx1 <= seg[i].first)
            {
                ans[seg[i].second[2]] = min(ans[seg[i].second[2]], seg[i].first - mx1);
            }
            else
            {
                ans[seg[i].second[2]] = 0;
            }
            c[seg[i].second[1]] = max(c[seg[i].second[1]], seg[i].second[0]);
            s.set(seg[i].second[1], c[seg[i].second[1]]);
        }

        for (lol i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;
}