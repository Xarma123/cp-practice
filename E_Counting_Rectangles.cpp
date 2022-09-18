#include <bits/stdc++.h>
#define lol long long
using namespace std;
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class SegmentTree
{
public:
    lol size;
    vector<vector<pair<lol, lol>>> seg;
    vector<vector<lol>> cs;
    SegmentTree(lol n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        seg.assign(2 * size, {});
        cs.assign(2 * size, {});
    }
    void merge(vector<pair<lol, lol>> a, vector<pair<lol, lol>> b, lol x)
    {

        lol i = 0, j = 0;
        seg[x].clear();
        while (i < a.size() && j < b.size())
        {
            if (a[i].first <= b[j].first)
            {
                seg[x].push_back(a[i]);
                i++;
            }
            else
            {
                seg[x].push_back(b[j]);
                j++;
            }
        }
        while (i < a.size())
        {
            seg[x].push_back(a[i]);
            i++;
        }
        while (j < b.size())
        {
            seg[x].push_back(b[j]);
            j++;
        }
        cs[x].clear();
        if (seg[x].size())
            cs[x].push_back(seg[x][0].second);
        for (i = 1; i < seg[x].size(); i++)
        {
            cs[x].push_back(cs[x].back() + seg[x][i].second);
        }
    }
    void set(lol i, lol v, lol a, lol x, lol lx, lol rx)
    {

        if (rx - lx == 1)
        {
            seg[x].clear();
            seg[x].push_back({v, a});
            cs[x].clear();
            cs[x].push_back(a);
            return;
        }
        lol m = (lx + rx) / 2;
        if (i < m)
            set(i, v, a, 2 * x + 1, lx, m);
        else
            set(i, v, a, 2 * x + 2, m, rx);
        merge(seg[2 * x + 1], seg[2 * x + 2], x);
    }
    void set(lol i, lol v, lol a)
    {
        set(i, v, a, 0, 0, size);
    }
    lol sum(lol l, lol r, lol mn, lol mx)
    {
        return sum(l, r, mn, mx, 0, 0, size);
    }
    lol sum(lol l, lol r, lol mn, lol mx, lol x, lol lx, lol rx)
    {
        if (lx >= r || l >= rx)
            return 0;
        if (lx >= l && rx <= r)
        {
            pair<lol, lol> a1 = {mx, LONG_LONG_MAX};
            pair<lol, lol> a2 = {mn, LONG_LONG_MAX};
            lol chote = lower_bound(seg[x].begin(), seg[x].end(), a1) - seg[x].begin();
            chote--;
            lol bade = upper_bound(seg[x].begin(), seg[x].end(), a2) - seg[x].begin();
            if (chote >= bade)
            {
                if (bade > 0)
                {
                    return cs[x][chote] - cs[x][bade - 1];
                }
                return cs[x][chote];
            }
            return 0;
        }

        lol m = (lx + rx) / 2;
        return sum(l, r, mn, mx, 2 * x + 1, lx, m) + sum(l, r, mn, mx, 2 * x + 2, m, rx);
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
        lol n, q;
        cin >> n >> q;
        SegmentTree s(n);
        pair<lol, lol> a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        sort(a, a + n);
        for (lol i = 0; i < n; i++)
        {
            s.set(i, a[i].second, a[i].first * 1ll * a[i].second);
        }
        while (q--)
        {
            lol h, w;
            cin >> h >> w;
            lol hb, wb;
            cin >> hb >> wb;
            pair<lol, lol> a1 = {hb, LONG_LONG_MAX};
            pair<lol, lol> a2 = {h, LONG_LONG_MAX};
            lol chote = lower_bound(a, a + n, a1) - a;
            lol bade = upper_bound(a, a + n, a2) - a;
            chote--;
            if (chote >= bade)
            {
                cout << s.sum(bade, chote, w, wb) << endl;
            }
            else
                cout << 0 << endl;
        }
    }
}
