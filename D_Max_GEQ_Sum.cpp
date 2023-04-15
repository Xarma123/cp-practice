#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segtree
{
public:
    vector<lol> sum, pre, suf;
    lol n;
    segtree(lol c)
    {
        n = 1;
        while (n < c)
            n = n * 2ll;
        sum.assign(2ll * n, 0);
        pre.assign(2ll * n, 0);
        suf.assign(2ll * n, 0);
    }
    void set(lol i, lol v, lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            suf[x] = max(v, 0ll);
            sum[x] = v;
            pre[x] = max(v, 0ll);
            return;
        }
        lol m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2ll * x + 1, lx, m);
        else
            set(i, v, 2ll * x + 2, m, rx);
        sum[x] = sum[2ll * x + 1] + sum[2ll * x + 2];
        pre[x] = max(pre[2ll * x + 1], pre[2ll * x + 2] + sum[2ll * x + 1]);
        suf[x] = max(suf[2ll * x + 2], suf[2ll * x + 1] + sum[2ll * x + 2]);
    }
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, n);
    }
    pair<lol, lol> pr(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lx >= l && rx <= r)
        {
            return {pre[x], sum[x]};
        }
        if (lx >= r || rx <= l)
        {
            return {0ll, 0ll};
        }
        lol m = (lx + rx) / 2;
        pair<lol, lol> sl = pr(l, r, 2ll * x + 1, lx, m);
        pair<lol, lol> sr = pr(l, r, 2ll * x + 2, m, rx);
        return {max(max(sl.first, sr.first + sl.second), 0ll), sl.second + sr.second};
    }
    lol pr(lol l, lol r)
    {
        return pr(l, r, 0, 0, n).first;
    }
    pair<lol, lol> su(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lx >= l && rx <= r)
        {
            return {suf[x], sum[x]};
        }
        if (lx >= r || rx <= l)
        {
            return {0ll, 0ll};
        }
        lol m = (lx + rx) / 2;
        pair<lol, lol> sl = su(l, r, 2ll * x + 1, lx, m);
        pair<lol, lol> sr = su(l, r, 2ll * x + 2, m, rx);
        return {max(max(sr.first, sr.second + sl.first), 0ll), sl.second + sr.second};
    }
    lol su(lol l, lol r)
    {
        return su(l, r, 0, 0, n).first;
    }
};
vector<pair<lol, lol>> prv_nx(lol a[], lol n)
{
    lol prv[n], nx[n];
    stack<lol> s;
    s.push(-1);
    for (lol i = 0; i < n; i++)
    {
        while (s.top() != -1 && a[s.top()] <= a[i])
        {
            lol v = s.top();
            s.pop();
            nx[v] = i;
        }
        prv[i] = s.top();
        s.push(i);
    }
    while (s.top() != -1)
    {
        lol v = s.top();
        s.pop();
        nx[v] = n;
    }
    vector<pair<lol, lol>> v(n);
    for (lol i = 0; i < n; i++)
    {
        v[i] = {prv[i], nx[i]};
    }
    return v;
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
        lol n;
        cin >> n;
        lol a[n];
        segtree s(n);
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s.set(i, a[i]);
        }
        bool ans = true;
        vector<pair<lol, lol>> v = prv_nx(a, n);

        for (lol i = 0; i < n; i++)
        {
            lol l = v[i].first;
            lol r = v[i].second;
            l++;
            lol vl = 0;
            if (i - l > 0)
            {
                vl += s.su(l, i);
            }
            lol vr = 0;
            if (r - i > 0)
            {
                vr += s.pr(i + 1, r);
            }   
            if (vl + vr > 0ll)
                ans = false;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}