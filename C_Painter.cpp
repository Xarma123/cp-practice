#include <bits/stdc++.h>
#define lol long long
using namespace std;
const lol N = 1e6 + 5;
struct node
{
    lol cb;
    lol cbs;
    bool full;
    bool lf;
    bool rt;
};
class segmentTree
{
public:
    vector<node> seg;
    vector<char> lazy;
    lol size;
    segmentTree()
    {
        size = 1;
        while (size < N)
            size *= 2;
        seg.assign(2 * size, {0ll, 0ll, (bool)false, (bool)false, (bool)false});
        lazy.assign(2 * size, 'n');
    }
    void add(lol l, lol r, char c)
    {

        add(l, r, c, 0, 0, size);
    }
    void propagate(lol x, lol lx, lol rx)
    {
        if (lazy[x] == 'n')
            return;
        if (rx - lx == 1)
        {
            lazy[x] = 'n';
            return;
        }
        lol m = (lx + rx) / 2;
        if (lazy[x] == 'W')
        {
            seg[2 * x + 1] = {0ll, 0ll, (bool)false, (bool)false, (bool)false};
            lazy[2 * x + 1] = 'W';
            seg[2 * x + 2] = {0ll, 0ll, (bool)false, (bool)false, (bool)false};
            lazy[2 * x + 2] = 'W';
        }
        else
        {
            seg[2 * x + 1] = {m - lx, 1ll, (bool)true, (bool)true, (bool)true};
            lazy[2 * x + 1] = 'B';
            seg[2 * x + 2] = {rx - m, 1ll, (bool)true, (bool)true, (bool)true};
            lazy[2 * x + 2] = 'B';
        }
        lazy[x] = 'n';
    }
    void add(lol l, lol r, char c, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l)
        {
            return;
        }
        if (lx >= l && rx <= r)
        {
            lazy[x] = c;
            if (lazy[x] == 'W')
            {
                seg[x] = {0ll, 0ll, (bool)false, (bool)false, (bool)false};
            }
            else
                seg[x] = {rx - lx, 1ll, (bool)true, (bool)true, (bool)true};
            return;
        }
        lol m = (lx + rx) / 2;
        add(l, r, c, 2 * x + 1, lx, m);
        add(l, r, c, 2 * x + 2, m, rx);
        seg[x].cb = seg[2 * x + 1].cb + seg[2 * x + 2].cb;
        seg[x].cbs = seg[2 * x + 1].cbs + seg[2 * x + 2].cbs;
        if (seg[2 * x + 1].rt && seg[2 * x + 2].lf)
            seg[x].cbs--;
        if (seg[2 * x + 1].full && seg[2 * x + 2].full)
            seg[x].full = true;
        else
            seg[x].full = false;
        if (seg[2 * x + 1].lf)
            seg[x].lf = true;
        else
            seg[x].lf = false;
        if (seg[2 * x + 2].rt)
            seg[x].rt = true;
        else
            seg[x].rt = false;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    segmentTree s;
    while (n--)
    {

        char c;
        cin >> c;
        lol l, r;
        cin >> l >> r;
        r = l + r;
        l += 5e5;
        r += 5e5;
        s.add(l, r, c);
        cout << s.seg[0].cbs << " " << s.seg[0].cb << endl;
    }

    return 0;
}