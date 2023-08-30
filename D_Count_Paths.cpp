#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol mod = 1e9 + 7;
class matrix
{
public:
    lol n;
    vector<vector<lol>> v;
    matrix(lol c)
    {
        v.assign(c, vector<lol>(c, 0));
        n = c;
    }
    void indentity()
    {
        for (lol i = 0; i < n; i++)
        {
            v[i][i] = 1;
        }
    }
    matrix operator*(matrix a)
    {
        matrix res(n);
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                for (lol k = 0; k < n; k++)
                {
                    res.v[i][j] += (v[i][k] * 1ll * a.v[k][j]) % mod;
                    res.v[i][j] %= mod;
                }
            }
        }
        return res;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    matrix a(n);
    while (m--)
    {
        lol x, y;
        cin >> x >> y;
        x--;
        y--;
        a.v[x][y] = 1;
    }
    matrix res(n);
    res.indentity();
    while (k > 0)
    {
        if (k & 1)
            res = a * res;
        a = a * a;
        k /= 2;
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            ans += res.v[i][j];
            ans %= mod;
        }
    }
    cout << ans;
}