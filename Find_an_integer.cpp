#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    vector<vector<lol>> a(n, vector<lol>(2));
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    for (lol i = 0; i < n; i++)
    {
        swap(a[i][0], a[i][1]);
    }
    sort(a.begin(), a.end());
    lol ans = 0;
    while (a.size())
    {

        lol suf[a.size()];
        for (lol i = a.size() - 1; i >= 0; i--)
        {
            suf[i] = a[i][0];
            if (i < a.size() - 1)
                suf[i] += suf[i + 1];
        }
        lol r = -1;
        lol val = LONG_LONG_MIN;
        for (lol i = 0; i < a.size(); i++)
        {
            lol j = a[i][1];
            lol b = (long long)a.size() - j;

            lol cval;
            if (b <= i)
            {
                b--;
                b = max(b, 0ll);
                cval = suf[b] - 2ll * a[i][0];
            }
            else if (b == a.size())
            {
                cval = -a[i][0];
            }
            else
            {
                cval = suf[b] - a[i][0];
            }

            if (val < cval)
            {
                val = cval;
                r = i;
            }
            else if (val == cval)
            {
                if (a[r][0] > a[i][0])
                {
                    r = i;
                }
            }
        }
        ans += val + a[r][0];
        lol b = (long long)a.size() - a[r][1];
        if (b > r)
        {
            while (a.size() >= b + 1)
            {
                a.pop_back();
            }
            a.erase(a.begin() + r);
        }
        else
        {
            b--;
            b = max(b, 0ll);
            while (a.size() >= b + 1)
            {
                a.pop_back();
            }
        }
    }
    cout << ans;

    return 0;
}
