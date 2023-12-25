#include <bits/stdc++.h>
using namespace std;
#define lol long long
class sparse_min
{
public:
    vector<vector<lol>> v;
    lol n;
    vector<lol> ln;
    sparse_min(vector<lol> a)
    {
        n = a.size();
        v.assign(n, vector<lol>(30, n));
        for (lol j = 0; j < 30; j++)
        {
            for (lol i = 0; i + (1ll << j) - 1 < n; i++)
            {
                if (j == 0)
                {
                    v[i][j] = a[i];
                }
                else
                {
                    v[i][j] = min(v[i][j - 1], v[i + (1ll << (j - 1))][j - 1]);
                }
            }
        }

        ln.assign(n + 1, 0);
        ln[1] = 0;
        for (lol i = 2; i <= n; i++)
        {
            ln[i] = 1 + ln[i / 2];
        }
    }
    lol query(lol l, lol r)
    {
        lol i = ln[r + 1 - l];
        return min(v[l][i], v[r - (1ll << i) + 1][i]);
    }
};

class sparse_mx
{
public:
    vector<vector<lol>> v;
    lol n;
    vector<lol> ln;
    sparse_mx(vector<lol> a)
    {
        n = a.size();
        v.assign(n, vector<lol>(30, 0));
        for (lol j = 0; j < 30; j++)
        {
            for (lol i = 0; i + (1ll << j) - 1 < n; i++)
            {
                if (j == 0)
                {
                    v[i][j] = a[i];
                }
                else
                {
                    v[i][j] = max(v[i][j - 1], v[i + (1ll << (j - 1))][j - 1]);
                }
            }
        }

        ln.assign(n + 1, 0);
        ln[1] = 0;
        for (lol i = 2; i <= n; i++)
        {
            ln[i] = 1 + ln[i / 2];
        }
    }
    lol query(lol l, lol r)
    {
        lol i = ln[r + 1 - l];
        return max(v[l][i], v[r - (1ll << i) + 1][i]);
    }
};
map<lol, vector<lol>> mp;
lol mx;
void dfs(lol c, lol cmp[])
{
    cmp[c] = mx;
    for (auto e : mp[c])
    {
        if (cmp[e] == -1)
        {
            dfs(e, cmp);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lol t;
    cin >> t;
    while (t--)
    {
        mx = 0;
        lol n;
        cin >> n;
        lol c[2ll * n];
        vector<lol> t(2ll * n);
        for (lol i = 0; i < 2ll * n; i++)
        {
            cin >> c[i];
        }
        lol l[n + 1];
        lol r[n + 1];
        lol f[n + 1];
        for (lol i = 0; i <= n; i++)
        {
            l[i] = 2ll * n;
            r[i] = -1;
            f[i] = 0;
        }

        for (lol i = 0; i < 2ll * n; i++)
        {
            l[c[i]] = min(l[c[i]], i);
            r[c[i]] = max(r[c[i]], i);
            f[c[i]]++;
        }
        for (lol i = 0; i < 2ll * n; i++)
        {
            t[i] = l[c[i]];
        }
        sparse_min smn(t);
        for (lol i = 0; i < 2ll * n; i++)
        {
            t[i] = r[c[i]];
        }
        sparse_mx smx(t);

        mp.clear();
        for (lol i = 1; i <= n; i++)
        {
            if (r[i] != -1)
            {
                lol lf = c[smn.query(l[i], r[i])];
                mp[i].push_back(lf);
                mp[lf].push_back(i);
                lol rt = c[smx.query(l[i], r[i])];
                mp[i].push_back(rt);
                mp[rt].push_back(i);
            }
        }

        vector<pair<lol, lol>> v;
        map<pair<lol, lol>, lol> mp;

        lol cmp[n + 1];
        memset(cmp, -1, sizeof(cmp));

        for (lol i = 1; i <= n; i++)
        {
            if (cmp[i] == -1)
            {
                mx++;
                dfs(i, cmp);
            }
        }
        map<lol, lol> cmpl;
        map<lol, lol> cmpr;
        for (lol i = 1; i <= n; i++)
        {
            if (!cmpl.count(cmp[i]))
            {
                cmpl[cmp[i]] = l[i];
            }
            else
            {
                cmpl[cmp[i]] = min(cmpl[cmp[i]], l[i]);
            }
            if (!cmpr.count(cmp[i]))
            {
                cmpr[cmp[i]] = r[i];
            }
            else
            {
                cmpr[cmp[i]] = max(cmpr[cmp[i]], r[i]);
            }
        }

        for (lol i = 1; i <= n; i++)
        {

            l[i] = cmpl[cmp[i]];
            r[i] = cmpr[cmp[i]];
            if (l[i] <= r[i])
            {
                if (!mp.count({l[i], r[i]}))
                    v.push_back({l[i], r[i]});
                mp[{l[i], r[i]}] += f[i];
            }
        }
        sort(v.rbegin(), v.rend());
        pair<lol, lol> dp[2 * n + 1];
        lol mod = 998244353;
        for (lol i = 0; i < 2ll * n; i++)
        {
            dp[i] = {LONG_LONG_MAX, 0};
        }
        dp[2ll * n] = {0, 1};
        for (auto e : v)
        {
            lol lf = e.first;
            lol rt = e.second;
            if (dp[rt + 1].first + 1 < dp[lf].first)
            {
                dp[lf].first = dp[rt + 1].first + 1;
                dp[lf].second = (mp[e] * 1ll * dp[rt + 1].second) % mod;
            }
            else if (dp[rt + 1].first + 1 == dp[lf].first)
            {
                dp[lf].second += (mp[e] * 1ll * dp[rt + 1].second) % mod;
                dp[lf].second %= mod;
            }
        }
        cout << dp[0].first << " " << dp[0].second << '\n';
    }

    return 0;
}
