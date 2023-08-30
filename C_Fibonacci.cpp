#include <bits/stdc++.h>
using namespace std;
#define lol long long
const long long n = 2;
lol mod = 1e9 + 7;
class matrix
{
public:
    lol m[n][n];
    matrix()
    {
        memset(m, 0, sizeof(m));
    }
    void identity()
    {
        for (lol i = 0; i < n; i++)
        {
            m[i][i] = 1;
        }
    }
    matrix operator*(matrix a)
    {
        matrix res;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                for (lol k = 0; k < n; k++)
                {
                    res.m[i][j] += (m[i][k] * 1ll * a.m[k][j]) % mod;
                    res.m[i][j] %= mod;
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
    lol q;
    cin >> q;
    if (q == 0)
        cout << 0;
    else if (q <= 2)
        cout << 1;
    else
    {
        matrix a;
        a.m[0][0] = 1;
        a.m[0][1] = 1;
        a.m[1][0] = 1;
        a.m[1][1] = 0;
        q -= 2;
        matrix res;
        res.identity();
        while (q > 0)
        {
            if (q & 1)
                res = a * res;
            q /= 2;
            a = a * a;
        }
        cout << (res.m[0][0] + res.m[0][1]) % mod;
    }
}