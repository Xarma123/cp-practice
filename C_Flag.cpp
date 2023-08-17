#include <bits/stdc++.h>
using namespace std;
#define lol long long
class segtree
{
public:
    lol n;
    vector<lol> seg;
    segtree(lol c)
    {
        n = 1;
        while (n < c)
            n = n * 2ll;
        seg.assign(2ll * n, LONG_LONG_MAX);
    }
    void set(lol i, lol v, lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            seg[x] = v;
            return;
        }
        lol m = (lx + rx) / 2ll;
        if (i < m)
        {
            set(i, v, 2ll * x + 1, lx, m);
        }
        else
            set(i, v, 2ll * x + 2, m, rx);
        seg[x] = min(seg[2ll * x + 1], seg[2ll * x + 2]);
    }
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, n);
    }
    lol mn(lol l, lol r, lol x, lol lx, lol rx)
    {
        lol m = (lx + rx) / 2;
        if (lx >= l && rx <= r)
            return seg[x];
        if (lx >= r || rx <= l)
        {
            return LONG_LONG_MAX;
        }

        return min(mn(l, r, 2ll * x + 1, lx, m), mn(l, r, 2ll * x + 2, m, rx));
    }
    lol mn(lol l, lol r)
    {
        return mn(l, r, 0, 0, n);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol nx[n][m];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            lol k = j + 1;
            while (k < m && a[i][j] == a[i][k])
                k++;
            for (lol l = j; l < k; l++)
            {
                nx[i][l] = k - l;
            }
            j = k - 1;
        }
    }

    vector<segtree> v;
    for (lol j = 0; j < m; j++)
    {
        segtree s(n);
        for (lol i = 0; i < n; i++)
        {
            s.set(i, nx[i][j]);
        }
        v.push_back(s);
    }
    lol nx2[n][m];
    for (lol j = 0; j < m; j++)
    {
        for (lol i = 0; i < n; i++)
        {
            lol k = i + 1;
            while (k < n && a[i][j] == a[k][j])
                k++;
            for (lol l = i; l < k; l++)
            {
                nx2[l][j] = k - l;
            }
            i = k - 1;
        }
    }
    lol nx3[n][m];
    for (lol j = 0; j < m; j++)
    {
        for (lol i = n - 1; i >= 0; i--)
        {
            lol k = i - 1;
            while (k >= 0 && a[i][j] == a[k][j])
                k--;
            for (lol l = i; l > k; l--)
            {
                nx3[l][j] = l - k;
            }
            i = k + 1;
        }
    }

    lol ans = 0;
    for (lol i = 1; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            if (a[i - 1][j] == a[i][j])
                continue;
            lol l = nx2[i][j];

            lol b = nx2[i][j] + i;
            if (b >= n)
                continue;
            if (nx2[b][j] < l)
            {
                continue;
            }
            if (nx3[i - 1][j] < l)
            {
                continue;
            }
            ans += v[j].mn(i - 1 - l + 1, b + l);
        }
    }
    cout << ans;
}