#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol modInverse(lol A, lol M)
{
    lol m0 = M;
    lol y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1)
    {
        lol q = A / M;
        lol t = M;
        M = A % M, A = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;

    return x;
}
lol cal(lol l, lol r, lol in[], lol n, lol suf[])
{
    lol v = suf[l];
    if (r + 1 < n)
        v = (((v - suf[r + 1]) % (9ll) + 9ll) % (9ll));
    v = (v * 1ll * in[n - 1 - r]) % (9ll);
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
        string s;
        cin >> s;
        lol w, q;
        cin >> w >> q;
        lol n = s.size();
        lol suf[n];
        lol pw[n + 1];
        pw[0] = 1;
        for (lol i = 1; i <= n; i++)
        {
            pw[i] = (pw[i - 1] * 10ll) % (9ll);
        }
        lol pwinv[n + 1];
        pwinv[0] = 1;
        lol xx = modInverse(10, 9);
        for (lol i = 1; i <= n; i++)
        {
            pwinv[i] = (pwinv[i - 1] * 1ll * xx) % (9ll);
        }
        for (lol i = n - 1; i >= 0; i--)
        {
            suf[i] = (pw[n - 1 - i] * 1ll * (s[i] - '0')) % (9ll);
            if (i < n - 1)
            {
                suf[i] = (suf[i] + suf[i + 1]) % (9ll);
            }
        }
        map<lol, set<lol>> mp;
        for (lol i = 0; i < n - w + 1; i++)
        {
            mp[cal(i, i + w - 1, pwinv, n, suf)].insert(i);
        }
        while (q--)
        {
            lol l, r, k;
            cin >> l >> r >> k;
            l--;
            r--;
            lol v = cal(l, r, pwinv, n, suf);
            vector<pair<lol, lol>> ans;
            for (lol i = 0; i < 9; i++)
            {
                lol r = (v * 1ll * i) % (9ll);
                if (r <= k)
                {
                    r = k - r;
                }
                else
                {
                    r = 9 - (r - k);
                }
                // i  q
                if (mp[r].size() > 0 && mp[i].size() > 0)
                {
                    if (r == i)
                    {
                        if (mp[r].size() > 1)
                        {
                            auto it = mp[r].begin();
                            auto it2 = it;
                            it2++;
                            ans.push_back({(*it), (*it2)});
                        }
                    }
                    else
                        ans.push_back({(*mp[i].begin()), (*mp[r].begin())});
                }
            }
            sort(ans.begin(), ans.end());
            if (ans.size() == 0)
                cout << -1 << " " << -1 << '\n';
            else
                cout << ans[0].first + 1 << " " << ans[0].second + 1 << '\n';
        }
    }

    return 0;
}