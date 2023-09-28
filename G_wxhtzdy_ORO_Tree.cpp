#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol n;
lol qq[200005];
vector<lol> mp[200005];
lol d[200005];
lol blift[200005][22];
lol bliftor[200005][22];
void dfs(lol c, lol p, lol l)
{
    blift[c][0] = p;
    d[c] = l;
    for (lol j = 1; j < 22; j++)
    {
        blift[c][j] = blift[blift[c][j - 1]][j - 1];
    }
    bliftor[c][0] = (qq[c] | qq[p]);
    for (lol j = 1; j < 22; j++)
    {
        bliftor[c][j] = bliftor[c][j - 1];
        bliftor[c][j] |= bliftor[blift[c][j - 1]][j - 1];
    }
    for (auto e : mp[c])
    {
        if (e != p)
        {
            dfs(e, c, l + 1);
        }
    }
}
lol lca(lol x, lol y)
{
    if (d[x] < d[y])
        swap(x, y);
    lol v = d[x] - d[y];
    for (lol i = 0; i < 22; i++)
    {
        if ((v & (1ll << i)))
        {
            x = blift[x][i];
        }
    }
    for (lol i = 21; i >= 0; i--)
    {
        if (blift[x][i] != blift[y][i])
        {
            x = blift[x][i];
            y = blift[y][i];
        }
    }
    if (x != y)
        return blift[x][0];
    return x;
}
lol lf(lol a, lol m)
{
    for (lol i = 0; i < 22; i++)
    {
        if ((m & (1ll << i)))
            a = blift[a][i];
    }
    return a;
}
lol cal(lol a, lol b, lol u)
{
    if (a == b)
        return qq[a];

    lol ans = 0;
    lol v = d[a] - d[u];
    for (lol i = 0; i < 22; i++)
    {
        if ((v & (1ll << i)))
        {
            ans |= bliftor[a][i];
            a = blift[a][i];
        }
    }
    a = b;
    v = d[a] - d[u];
    for (lol i = 0; i < 22; i++)
    {
        if ((v & (1ll << i)))
        {
            ans |= bliftor[a][i];
            a = blift[a][i];
        }
    }
    return ans;
}
pair<lol, lol> solve(lol a, lol b, lol u, lol bit)
{
    lol n = d[a] + d[b] - 2ll * d[u];

    // 0  ---  n
    lol s = -1, e = n + 1;
    while (s != e - 1)
    {
        lol m = (s + e) / 2;
        if (m == n + 1)
        {
            e = m;
        }
        else if (m == -1)
            s = m;
        else
        {
            lol o;
            lol v = d[a] - d[u];
            lol val;
            if (m <= v)
            {
                o = lf(a, m);
                val = cal(a, o, o);
            }
            else
            {
                o = lf(b, n - m);
                val = cal(a, o, u);
            }

            if ((val & (1ll << bit)))
                e = m;
            else
                s = m;
        }
    }

    if (e == n + 1)
        return {-1, -1};
    pair<lol, lol> ans;
    ans.first = e;
    swap(a, b);
    s = -1, e = n + 1;
    while (s != e - 1)
    {
        lol m = (s + e) / 2;
        if (m == n + 1)
        {
            e = m;
        }
        else if (m == -1)
            s = m;
        else
        {
            lol o;
            lol v = d[a] - d[u];
            lol val;
            if (m <= v)
            {
                o = lf(a, m);
                val = cal(a, o, o);
            }
            else
            {
                o = lf(b, n - m);
                val = cal(a, o, u);
            }

            if ((val & (1ll << bit)))
                e = m;
            else
                s = m;
        }
    }

    ans.second = n - e;
    return ans;
}
lol solve2(vector<pair<lol, lol>> &v)
{
    vector<lol> l, r;
    for (lol i = 0; i < v.size(); i++)
    {
        l.push_back(v[i].first);
        r.push_back(v[i].second);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    lol c = 0;
    lol i = 0, j = 0;
    lol mx = 0;
    while (i < l.size())
    {
        if (l[i] <= r[j])
        {
            c++;
            i++;
        }
        else
        {
            c--;
            j++;
        }
        mx = max(mx, c);
    }
    return mx;
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
        cin >> n;
        qq[0] = 0;
        d[0] = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> qq[i + 1];
            mp[i + 1].clear();
            d[i + 1] = 0;
        }
        for (lol i = 0; i < n - 1; i++)
        {
            lol x, y;
            cin >> x >> y;
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        for (lol i = 1; i <= n; i++)
        {
            for (lol j = 0; j < 22; j++)
            {
                blift[i][j] = 0;
                bliftor[i][j] = 0;
            }
        }
        dfs(1, 0, 0);
        lol q;
        cin >> q;
        while (q--)
        {
            lol x, y;
            cin >> x >> y;
            lol up = lca(x, y);
            vector<pair<lol, lol>> all;
            for (lol i = 0; i < 31; i++)
            {
                pair<lol, lol> v = solve(x, y, up, i);
                if (v.first != -1)
                    all.push_back(v);
            }
            cout << (long long)all.size() + solve2(all) << ' ';
        }
        cout << '\n';
    }
}