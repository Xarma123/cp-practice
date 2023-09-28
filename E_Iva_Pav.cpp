#include <bits/stdc++.h>
using namespace std;
#define lol long long
class sparse
{
public:
    vector<vector<lol>> s;
    lol n;
    vector<lol> lg;
    sparse(lol a[], lol c)
    {
        s.assign(c, vector<lol>(25, 0));
        n = c;
        for (lol i = 0; i < n; i++)
        {
            s[i][0] = a[i];
        }
        for (lol j = 1; j < 25; j++)
        {
            for (lol i = 0; i+(1ll<<j)-1 < n; i++)
            {
                s[i][j] = (s[i][j - 1] & s[i + (1ll << (j-1))][j - 1]);
            }
        }
        lg.assign(n + 1, 0);
        lg[1] = 0;
        for (lol i = 2; i <= n; i++)
        {
            lg[i] = lg[i / 2] + 1;
        }
    }
    lol val(lol l, lol r)
    {
        lol x = lg[r - l + 1];
        return (s[l][x] & s[r - (1ll << x) + 1][x]);
    }
};
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
        {
            cin >> a[i];
        }
        sparse b(a, n);
        lol q;
        cin >> q;
        while (q--)
        {
            lol l, k;
            cin >> l >> k;
            l--;
            if (a[l] < k)
            {
                cout << -1 << ' ';
            }
            else
            {
                lol s = l, e = n;
                while (s != e - 1)
                {
                    lol m = (s + e) / 2ll;
                    if (m == n)
                    {
                        e = m;
                    }
                    else if (b.val(l, m) >= k)
                        s = m;
                    else
                        e = m;
                }
                cout << s + 1 << " ";
            }
          
        }
        cout << '\n';
    }
}