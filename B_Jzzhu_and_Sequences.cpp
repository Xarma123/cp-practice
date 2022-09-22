#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol m = 1e9 + 7;
struct matrice
{
    lol a[2][2];
    void identiy()
    {
        a[0][0] = 1;
        a[0][1] = 0;
        a[1][0] = 0;
        a[1][1] = 1;
    }
    matrice operator*(matrice b)
    {
        matrice r;
        for (lol i = 0; i < 2; i++)
        {
            for (lol j = 0; j < 2; j++)
            {
                r.a[i][j] = 0;
                for (lol k = 0; k < 2; k++)
                {
                    r.a[i][j] = (r.a[i][j] + (a[i][k] * 1ll * b.a[k][j] + m) % m + m) % m;
                }
            }
        }
        return r;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol x, y, n;
    cin >> x >> y >> n;
    if (n <= 2)
    {
        if (n == 1)
            cout << (x + m) % m;
        else
            cout << (y + m) % m;
    }
    else
    {
        matrice a;
        a.a[0][0] = a.a[1][0] = 1;
        a.a[0][1] = -1;
        a.a[1][1] = 0;
        matrice r;
        r.identiy();
        n -= 2;
        while (n > 0)
        {
            if (n % 2 != 0)
                r = r * a;
            n /= 2;
            a = a * a;
        }

        cout << ((y * 1ll * r.a[0][0] + m) % m + (x * 1ll * r.a[0][1] + m) % m + m) % m;
    }

    return 0;
}