#include <bits/stdc++.h>
#define lol long long
using namespace std;
class SegmentTree
{
public:
    lol size;
    vector<lol> seg;
    SegmentTree(lol n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        seg.assign(2 * size, 0);
        for (lol i = 0; i < n; i++)
        {
            set(i, 1);
        }
    }
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, size);
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
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
            set(i, v, 2 * x + 2, m, rx);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    lol ans(lol k)
    {
        return ans(k + 1, 0, 0, size);
    }
    lol ans(lol s, lol x, lol lx, lol rx)
    {
        if (seg[x] < s)
            return -1;
        if (rx - lx == 1)
        {
            return lx;
        }
        lol m = (lx + rx) / 2;
        lol s1 = ans(s, 2 * x + 2, m, rx);
        if (s1 == -1)
            return ans(s - seg[2 * x + 2], 2 * x + 1, lx, m);
        return s1;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    SegmentTree s(n);
    vector<lol> a;
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        a.push_back(t);
    }
    stack<lol> x;
    for (lol i = n - 1; i >= 0; i--)
    {
        x.push(s.ans(a[i]) + 1);
        s.set(x.top() - 1, 0);
    }
    while (!x.empty())
    {
        cout << x.top() << " ";
        x.pop();
    }

    return 0;
}