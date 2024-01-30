#include <bits/stdc++.h>
using namespace std;
#define lol long long
vector<vector<lol>> pre[317], pre2[317];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, q;
        cin >> n >> q;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 1; i <= 316 && i <= n + 10; i++)
        {
            pre[i].clear();
            pre2[i].clear();
            for (lol j = 0; j < i && j < n; j++)
            {

                vector<lol> v;
                lol c = 1;
                for (lol k = j; k < n; k += i)
                {
                    v.push_back((a[k] * 1ll * c));
                    c++;
                }

                for (lol k = 1; k < v.size(); k++)
                {
                    v[k] += v[k - 1];
                }

                pre[i].push_back(v);
                v.clear();
                for (lol k = j; k < n; k += i)
                {
                    v.push_back(a[k]);
                }
                for (lol k = 1; k < v.size(); k++)
                {
                    v[k] += v[k - 1];
                }
                pre2[i].push_back(v);
            }
        }

        while (q--)
        {
            lol s, d, k;
            cin >> s >> d >> k;
            s--;
            if (k == 1)
            {
                cout << a[s] << " ";
                continue;
            }
            if (d >= 316ll)
            {
                lol ans = 0;
                lol c = 1;
                for (lol i = s; i <= s + (k - 1) * 1ll * d; i += d, c++)
                {
                    ans += a[i] * 1ll * (c);
                }
                cout << ans << ' ';
            }
            else
            {
                lol r = s % d;
                lol v = pre[d][r][s / d + k - 1];
                if (s / d >= 1)
                {
                    v -= pre[d][r][(s / d) - 1];
                }

                lol v1 = pre2[d][r][s / d + k - 1];
                if (s / d >= 1)
                {
                    v1 -= pre2[d][r][(s / d) - 1];
                }
                cout << v - v1 * 1ll * (s / d) << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}
