#include <bits/stdc++.h>
using namespace std;
#define lol long long
class sparse
{
public:
    vector<vector<lol>> v;
    lol n;
    vector<lol> lg;
    sparse(lol a[], lol c)
    {
        n = c;
        v.assign(n, vector<lol>(30, LONG_LONG_MAX));
        lg.assign(n + 5, 0);
        lg[1] = 0;
        for (lol i = 2; i < lg.size(); i++)
        {
            lg[i] = lg[i / 2] + 1;
        }

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
                    v[i][j] = min(v[i][j - 1], v[i + (1ll << (j-1))][j - 1]);
                }
            }
        }
    }
    lol mn(lol l, lol r)
    {

        lol j = lg[r + 1 - l];
        return min(v[l][j], v[r - ((1ll << j) - 1)][j]);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sparse s(a, n);

    while (q--)
    {
        lol l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << s.mn(l, r) << '\n';
    }
}