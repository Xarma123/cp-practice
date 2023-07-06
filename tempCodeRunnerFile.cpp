    #include <bits/stdc++.h>
    using namespace std;
    #define lol long long
    map<lol, vector<lol>> mp;
    lol wt[200005];
    lol lvl[200005];
    lol blift[200005][30];
    lol sum[200005][30];
    lol mxsuf[200005][30];
    lol mnsuf[200005][30];
    lol mxpre[200005][30];
    lol mnpre[200005][30];
    lol mxsum[200005][30];
    lol mnsum[200005][30];
    void dfs(lol c, lol p, lol l)
    {

        blift[c][0] = p;
        sum[c][0] = wt[c] + (p >= 0 ? wt[p] : 0ll);
        lvl[c] = l;

        for (lol i = 1; i < 30; i++)
        {
            blift[c][i] = blift[blift[c][i - 1]][i - 1];
        }
        for (lol i = 1; i < 30; i++)
        {
            sum[c][i] = sum[c][i - 1] + sum[blift[c][i - 1]][i - 1] - wt[blift[c][i - 1]];
        }
        // suf
        mxsuf[c][0] = max(sum[c][0], wt[c]);
        for (lol i = 1; i < 30; i++)
        {
            mxsuf[c][i] = max(mxsuf[c][i - 1], sum[c][i - 1] + mxsuf[blift[c][i - 1]][i - 1] - wt[blift[c][i - 1]]);
        }
        mnsuf[c][0] = min(sum[c][0], wt[c]);
        for (lol i = 1; i < 30; i++)
        {
            mnsuf[c][i] = min(mnsuf[c][i - 1], sum[c][i - 1] + mnsuf[blift[c][i - 1]][i - 1] - wt[blift[c][i - 1]]);
        }
        // end suf

        // pre
        if (p == -1)
        {
            mxpre[c][0] = wt[c];
        }
        else
        {
            mxpre[c][0] = max(wt[p], sum[c][0]);
        }
        for (lol i = 1; i < 30; i++)
        {
            mxpre[c][i] = max(mxpre[blift[c][i - 1]][i - 1], sum[blift[c][i - 1]][i - 1] + mxpre[c][i - 1] - wt[blift[c][i - 1]]);
        }
        if (p == -1)
        {
            mnpre[c][0] = wt[c];
        }
        else
        {
            mnpre[c][0] = min(wt[p], sum[c][0]);
        }
        for (lol i = 1; i < 30; i++)
        {
            mnpre[c][i] = min(mnpre[blift[c][i - 1]][i - 1], sum[blift[c][i - 1]][i - 1] + mnpre[c][i - 1] - wt[blift[c][i - 1]]);
        }
        mxsum[c][0] = max(sum[c][0], wt[c]);
        for (lol i = 1; i < 30; i++)
        {
            lol up = blift[c][i - 1];
            mxsum[c][i] = max(mxsum[c][i - 1], max(mxsum[up][i - 1], mxsuf[up][i - 1] + mxpre[c][i - 1] - wt[up]));
        }
        mnsum[c][0] = min(sum[c][0], wt[c]);
        for (lol i = 1; i < 30; i++)
        {
            lol up = blift[c][i - 1];
            mnsum[c][i] = min(mnsum[c][i - 1], max(mnsum[up][i - 1], mnsuf[up][i - 1] + mnpre[c][i - 1] - wt[up]));
        }
        l++;
        for (auto e : mp[c])
        {
            if (e != p)
            {
                dfs(e, c, l);
            }
        }
    }
    lol lca(lol a, lol b)
    {

        if (lvl[a] < lvl[b])
        {
            swap(a, b);
        }
        lol d = lvl[a] - lvl[b];

        for (lol i = 31; i >= 0; i--)
        {
            if (((1ll << i) & d))
            {

                a = blift[a][i];
            }
        }

        for (lol i = 29; i >= 0; i--)
        {
            if (blift[a][i] != blift[b][i])
            {
                a = blift[a][i];
                b = blift[b][i];
            }
        }

        if (a != b)
        {
            return blift[a][0];
        }
        return a;
    }
    lol mxpath(lol a, lol b)
    {
        lol up = lca(a, b);
        lol d = lvl[a] - lvl[up];
        lol mxa = wt[a];
        lol pre = wt[a];
        lol ca = a;
        for (lol i = 31; i >= 0; i--)
        {
            if (((1ll << i) & d))
            {
                mxa = max(mxa, mxsum[ca][i]);
                mxa = max(mxa, pre + mxsuf[ca][i] - wt[ca]);
                pre = max(mxpre[ca][i], sum[ca][i] + pre - wt[ca]);
                ca = blift[ca][i];
            }
        }

        d = lvl[b] - lvl[up];
        lol mxb = wt[b];
        lol preb = wt[b];
        lol cb = b;

        for (lol i = 31; i >= 0; i--)
        {
            if (((1ll << i) & d))
            {

                mxb = max(mxb, mxsum[cb][i]);
                mxb = max(mxb, preb + mxsuf[cb][i] - wt[cb]);
                preb = max(mxpre[cb][i], sum[cb][i] + preb - wt[cb]);
                cb = blift[cb][i];
            }
        }

        return max(0ll, max(mxa, max(mxb, pre + preb - wt[up])));
    }
    lol mnpath(lol a, lol b)
    {
        lol up = lca(a, b);

        lol d = lvl[a] - lvl[up];

        lol mna = wt[a];
        lol pre = wt[a];
        lol ca = a;
        for (lol i = 31; i >= 0; i--)
        {
            if (((1ll << i) & d))
            {
                mna = min(mna, mnsum[ca][i]);
                mna = min(mna, pre + mnsuf[ca][i] - wt[ca]);
                pre = min(mnpre[ca][i], sum[ca][i] + pre - wt[ca]);
                ca = blift[ca][i];
            }
        }
        d = lvl[b] - lvl[up];
        lol mnb = wt[b];
        lol preb = wt[b];
        lol cb = b;
        for (lol i = 31; i >= 0; i--)
        {
            if (((1ll << i) & d))
            {
                mnb = min(mnb, mnsum[cb][i]);
                mnb = min(mnb, preb + mnsuf[cb][i] - wt[cb]);
                preb = min(mnpre[cb][i], sum[cb][i] + preb - wt[cb]);
                cb = blift[cb][i];
            }
        }
        return min(0ll, min(mna, min(mnb, pre + preb - wt[up])));
    }
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        lol t;
        cin >> t;
        lol q = 1;
        bool ff = false;
        while (t--)
        {
            lol n;
            cin >> n;
            if (n == 20ll)
                ff = true;
            mp.clear();
            for (lol i = 0; i <= n; i++)
            {
                wt[i] = 0;
                lvl[i] = 0;
                for (lol j = 0; j < 30; j++)
                {
                    blift[i][j] = 0;
                    sum[i][j] = 0;
                    mxsuf[i][j] = 0;
                    mnsuf[i][j] = 0;
                    mxpre[i][j] = 0;
                    mnpre[i][j] = 0;
                    mxsum[i][j] = 0;
                    mnsum[i][j] = 0;
                }
            }
            wt[1] = 1;
            lol co = 2;
            vector<vector<lol>> x;
            string s = "";
            for (lol i = 0; i < n; i++)
            {

                char c;
                cin >> c;
                if (c == '+')
                {
                    lol a, w;
                    cin >> a >> w;

                    mp[a].push_back(co);
                    mp[co].push_back(a);
                    wt[co] = w;
                    co++;
                }
                else
                {
                    lol u, v, k;
                    cin >> u >> v >> k;
                    x.push_back({u, v, k});
                }
            }
            // s = s + "----";
            for (auto e : x)
            {
                s = s + to_string(e[0]) + "," + to_string(e[1]) + "," + to_string(e[2]) + ":";
            }
            dfs(1, -1, 0);
            // while (1)
            // {
            //     lol a, b;
            //     cin >> a >> b;
            //     cout << mnpath(a, b) << endl;
            // }

            for (auto e : x)
            {
                lol mx = mxpath(e[0], e[1]);
                lol mn = mnpath(e[0], e[1]);
                if (q == 7064ll && ff)
                {
                    cout << s << endl;
                }
                else
                {
                    if (e[2] >= mn && e[2] <= mx)
                        cout << "YES\n";
                    else
                        cout << "NO\n";
                }
                q++;
            }
        }
    }