#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol med(lol a, lol b, lol c, lol d)
{
    vector<lol> x;
    x.push_back(a);
    x.push_back(b);
    x.push_back(c);
    x.push_back(d);
    sort(x.begin(), x.end());
    return x[1];
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
        lol n, m;
        cin >> n >> m;
        lol a[n][m];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        lol s = 0, e = n - 1;
        lol ans = 0;
        while (s <= e)
        {
            lol l = 0, r = m - 1;
            while (l <= r)
            {
                if (s != e && l != r)
                {
                    lol v = med(a[s][l], a[e][l], a[s][r], a[e][r]);
                    ans += abs(v - a[s][l]);
                    ans += abs(v - a[e][l]);
                    ans += abs(v - a[s][r]);
                    ans += abs(v - a[e][r]);
                }
                else if (s == e && l != r)
                {
                    lol v = med(a[s][l], a[e][l], a[s][r], a[e][r]);
                    ans += abs(v - a[e][l]);
                    ans += abs(v - a[s][r]);
                }
                else if (s != e && l == r)
                {
                    lol v = med(a[s][l], a[e][l], a[s][r], a[e][r]);
                    ans += abs(v - a[e][l]);
                    ans += abs(v - a[s][r]);
                }
                l++;
                r--;
            }
            s++;
            e--;
        }
        cout << ans << '\n';
    }
}