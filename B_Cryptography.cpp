#include <bits/stdc++.h>
#define lol long long
using namespace std;
struct Matrix
{
    lol a11;
    lol a12;
    lol a21;
    lol a22;
};

lol r;
Matrix prod(Matrix a, Matrix b)
{
    return {((a.a11 * b.a11) % r + (a.a12 * b.a21) % r) % r,
            ((a.a11 * b.a12) % r + (a.a12 * b.a22) % r) % r,
            ((a.a21 * b.a11) % r + (a.a22 * b.a21) % r) % r,
            ((a.a21 * b.a12) % r + (a.a22 * b.a22) % r) % r};
}
class SegmentTree
{
public:
    lol size;
    vector<Matrix> seg;
    SegmentTree(vector<Matrix> &a)
    {
        size = 1;
        while (size < a.size())
            size *= 2;
        size *= 2;
        seg.assign(2 * size, {1, 0, 0, 1});
        for (lol i = 0; i < a.size(); i++)
        {
            set(i, a[i]);
        }
    }
    void set(lol i, Matrix v)
    {
        set(i, v, 0, 0, size);
    }
    void set(lol i, Matrix v, lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            seg[x] = v;
            return;
        }
        lol m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        seg[x] = prod(seg[2 * x + 1], seg[2 * x + 2]);
    }
    Matrix sum(lol l, lol r)
    {
        return sum(l, r, 0, 0, size);
    }
    Matrix sum(lol l, lol r, lol x, lol lx, lol rx)
    {

        if (lx >= r || rx <= l)
            return {1, 0, 0, 1};
        if (lx >= l && rx <= r)
            return seg[x];
        lol m = (lx + rx) / 2;
        return prod(sum(l, r, 2 * x + 1, lx, m), sum(l, r, 2 * x + 2, m, rx));
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> r >> n >> m;
    vector<Matrix> a;
    for (lol i = 0; i < n; i++)
    {
        Matrix x;
        cin >> x.a11 >> x.a12 >> x.a21 >> x.a22;
        a.push_back(x);
    }
    SegmentTree s(a);
    while (m--)
    {
        lol l, r;
        cin >> l >> r;
        l--;
        Matrix x = s.sum(l, r);
        cout << x.a11 << " " << x.a12 << '\n';
        cout << x.a21 << " " << x.a22 << '\n';
        cout << '\n';
    }

    return 0;
}