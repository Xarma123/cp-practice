#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol m, n, k, t;
    cin >> m >> n >> k >> t;
    lol a[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    vector<pair<lol, vector<lol>>> v;
    for (lol i = 0; i < k; i++)
    {
        lol l, r, d;
        cin >> l >> r >> d;
        v.push_back({l, {r, d}});
    }
    sort(v.begin(), v.end());
    sort(a, a + m);
    lol s = 0, e = m + 1;
    while (s != e - 1)
    {

        lol md = (s + e) / 2;

        if (md == 0)
            s = md;
        else if (md == m + 1)
            e = md;
        else
        {

            lol mxd = a[m - md];
            lol dd = 0;
            lol c = 0;
            for (lol i = 0; i < k; i++)
            {
                if (v[i].second[1] > mxd)
                {
                    lol j = i + 1;
                    lol mxr = v[i].second[0];
                    while (j < k && v[j].first <= mxr)
                    {
                        if (v[j].second[1] > mxd)
                            mxr = max(mxr, v[j].second[0]);
                        j++;
                    }
                    c += mxr - v[i].first + 1;
                    c += mxr - v[i].first + 1;
                    i = j - 1;
                }
            }
            c += n + 1;

            if (c <= t)
                s = md;
            else
                e = md;
        }
    }
    cout << s;
}