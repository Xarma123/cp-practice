#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segTree
{
public:
    vector<lol> tree;
    lol n;
    segTree(lol c)
    {
        n = 1;
        while (n < c)
        {
            n = n * 2ll;
        }
        tree.assign(2ll * n, 1);
    }
    void set(lol i, lol v, lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            if (v > 0)
                v = 1;
            else if (v < 0)
                v = -1;
                
            tree[x] = v;
            return;
        }
        lol m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v, 2ll * x + 1, lx, m);
        }
        else
            set(i, v, 2ll * x + 2, m, rx);
        tree[x] = tree[2ll * x + 1] * 1ll * tree[2ll * x + 2];
    }
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, n);
    }
    lol sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lx >= l && rx <= r)
        {
            return tree[x];
        }
        if (l >= rx || r <= lx)
            return 1ll;
        lol m = (lx + rx) / 2;
        return (sum(l, r, 2ll * x + 1, lx, m) * 1ll * sum(l, r, 2ll * x + 2, m, rx));
    }
    lol sum(lol l, lol r)
    {
        return sum(l, r, 0, 0, n);
    }
    void print()
    {
        for (auto e : tree)
            cout << e << " ";
        cout << endl;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    while (cin >> n >> k)
    {

        segTree s(n);
        for (lol i = 0; i < n; i++)
        {
            lol v;
            cin >> v;
            s.set(i, v);
        }

        while (k--)
        {
            char C;
            cin >> C;
            if (C == 'C')
            {
                lol i, v;
                cin >> i >> v;
                i--;
                s.set(i, v);
            }
            else
            {
                lol l, r;
                cin >> l >> r;
                l--;
                lol q = s.sum(l, r);
                if (q == 0)
                    cout << 0;
                else if (q > 0)
                    cout << '+';
                else
                    cout << '-';
            }
        }
        cout << endl;
    }

    return 0;
}