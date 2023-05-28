#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol sparse[300005][30];
lol mx(lol a, lol b)
{
    lol x = log2l(b + 1 - a);
    return max(sparse[a][x], sparse[b - ((1ll << x) - 1)][x]);
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
        for (lol i = 0; i < n; i++)
            cin >> a[i];
        for (lol j = 0; j < 30; j++)
        {
            for (lol i = 0; i + (1ll << j) - 1 < n; i++)
            {
                if (j == 0)
                    sparse[i][j] = a[i];
                else
                {
                    sparse[i][j] = max(sparse[i][j - 1], sparse[i + (1ll << (j - 1))][j - 1]);
                }
            }
        }

        stack<lol> s;
        s.push(-1);
        lol pv_s[n];
        lol nx_s[n];
        for (lol i = 0; i < n; i++)
        {
            while (s.top() != -1 && a[s.top()] > a[i])
            {
                nx_s[s.top()] = i;
                s.pop();
            }
            pv_s[i] = s.top();
            s.push(i);
        }
        while (s.top() != -1)
        {
            nx_s[s.top()] = n;
            s.pop();
        }
        lol ans = (n - 1) * 1ll * (n)*1ll * (n + 1) / 6ll;
        for (lol i = 0; i < n; i++)
        {
            lol k = pv_s[i];
            if (k != -1)
            {
                lol j = k;
                lol st = -1, e = j;
                while (st != e - 1)
                {
                    lol m = (st + e) / 2ll;
                    if (m == -1)
                        st = m;
                    else if (m == j)
                        e = m;
                    else if (mx(m, j) > a[i])
                        st = m;
                    else
                        e = m;
                }
                j = st;
                ans -= (k - j) * 1ll * (nx_s[i] - i);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}