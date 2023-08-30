#include <bits/stdc++.h>
using namespace std;
#define lol long long
const long long n = 2;
class matrix
{
public:
    long double m[n][n];
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
        res.identity();
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                res.m[i][j] = 0;
                for (lol k = 0; k < n; k++)
                {
                    res.m[i][j] += m[i][k] * a.m[k][j];
                }
            }
        }
        return res;
    }
    void print()
    {
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                cout << m[i][j] << " ";
            }
            cout << '\n';
        }
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol q;
    long double p;
    cin >> q >> p;
    matrix a;
    a.m[0][0] = 1 - 2 * p;
    a.m[0][1] = p;
    a.m[1][0] = 0;
    a.m[1][1] = 1;
    matrix res;
    res.identity();
  
    while (q > 0)
    {
        if ((q & 1))
        {
            res = a * res;
        }
        a = a * a;
        q /= 2;
       
    }
    cout << fixed << setprecision(10) << res.m[0][0] + res.m[0][1];
}