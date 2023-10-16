#include <bits/stdc++.h>
using namespace std;
#define lol long long
class segmentTree
{
public:
    vector<lol> seg;
    vector<lol> lazy;
    lol size;
    segmentTree(lol n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        seg.assign(2 * size, 0);
        lazy.assign(2 * size, 0);
    }
    void add(lol l, lol r, lol v)
    {
        add(l, r, v, 0, 0, size);
    }
    void add(lol l, lol r, lol v, lol x, lol lx, lol rx)
    {
        if (lazy[x] != 0)
        {
            seg[x] += lazy[x] * (rx - lx);
            if (rx - lx != 1)
            {
                lazy[2 * x + 1] += lazy[x];
                lazy[2 * x + 2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if (lx >= r || rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            seg[x] += v * (rx - lx);
            if (rx - lx != 1)
            {
                lazy[2 * x + 1] += v;
                lazy[2 * x + 2] += v;
            }
            return;
        }
        lol m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    lol sum(lol l, lol r)
    {
        return sum(l, r, 0, 0, size);
    }
    lol sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lazy[x] != 0)
        {
            seg[x] += lazy[x] * (rx - lx);
            if (rx - lx != 1)
            {
                lazy[2 * x + 1] += lazy[x];
                lazy[2 * x + 2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if (lx >= r || rx <= l)
            return 0;
        if (lx >= l && rx <= r)
        {
            return seg[x];
        }
        lol m = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
    }
};
char char_at(lol i, segmentTree &a, string &s)
{
    lol v = a.sum(i, i + 1);
    v %= 26ll;
    v = ((s[i] - 'a') + v) % 26ll;
    return char('a' + v);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        segmentTree a(n);
        set<lol> tw, thre;
        for (lol i = 0; i < n; i++)
        {
            if (i + 1 < n && s[i] == s[i + 1])
            {
                tw.insert(i);
            }
            if (i + 2 < n && s[i] == s[i + 2])
            {
                thre.insert(i);
            }
        }

        while (m--)
        {
            lol c;
            cin >> c;
            if (c == 1)
            {
                lol l, r, x;
                cin >> l >> r >> x;
                l--;
                a.add(l, r, x);
                if (l - 1 >= 0)
                {
                    if (char_at(l - 1, a, s) == char_at(l, a, s))
                    {
                        tw.insert(l - 1);
                    }
                    else
                    {
                        if (tw.count(l - 1))
                            tw.erase(l - 1);
                    }
                }
                if (r < n)
                {
                    if (char_at(r - 1, a, s) == char_at(r, a, s))
                    {
                        tw.insert(r - 1);
                    }
                    else
                    {
                        if (tw.count(r - 1))
                            tw.erase(r - 1);
                    }
                }
                if (l - 2 >= 0)
                {
                    if (char_at(l - 2, a, s) == char_at(l, a, s))
                    {
                        thre.insert(l - 2);
                    }
                    else
                    {
                        if (thre.count(l - 2))
                            thre.erase(l - 2);
                    }
                }
                if (l - 1 >= 0 && l + 1 < n)
                {
                    if (char_at(l - 1, a, s) == char_at(l + 1, a, s))
                    {
                        thre.insert(l - 1);
                    }
                    else
                    {
                        if (thre.count(l - 1))
                            thre.erase(l - 1);
                    }
                }
                if (r < n && r - 2 >= 0)
                {
                    if (char_at(r - 2, a, s) == char_at(r, a, s))
                    {
                        thre.insert(r - 2);
                    }
                    else
                    {
                        if (thre.count(r - 2))
                            thre.erase(r - 2);
                    }
                }
                if (r + 1 < n && r - 1 >= 0)
                {
                    if (char_at(r - 1, a, s) == char_at(r + 1, a, s))
                    {
                        thre.insert(r - 1);
                    }
                    else
                    {
                        if (thre.count(r - 1))
                            thre.erase(r - 1);
                    }
                }
            }
            else
            {
                lol l, r;
                cin >> l >> r;
                l--;

                auto it = tw.lower_bound(l);
                if (it != tw.end() && (*it) + 1 < r)
                {
                    cout << "NO\n";
                    continue;
                }
                it = thre.lower_bound(l);
                if (it != thre.end() && (*it) + 2 < r)
                {
                    cout << "NO\n";
                    continue;
                }
                cout << "YES\n";
            }
        }
    }
}