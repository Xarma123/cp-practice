#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol N = n;
        vector<lol> f;
        while (n % 2 == 0)
        {
            if (f.size() == 0)
                f.push_back(2);
            n = n / 2;
        }

        for (lol i = 3; i <= sqrtl(n); i = i + 2)
        {
            if (n % i == 0)
            {
                f.push_back(i);
            }

            while (n % i == 0)
            {

                n = n / i;
            }
        }
        if (n > 2)
            f.push_back(n);

        if (f.size() < 2)
        {

            lol a = f[0];
            N = N / a;
            lol b = f[0] * f[0];
            N = N / b;
            if (N > b)
            {
                cout << "YES" << endl;
                cout << a << " " << b << " " << N << endl;
            }
            else
                cout << "NO" << endl;
        }
        else
        {
            N = N / f[0];
            N = N / f[1];
            if (N <= 1 || N == f[0] || N == f[1])
                cout << "NO" << endl;
            else
            {
                cout << "YES" << endl;
                cout << f[0] << " " << f[1] << " " << N << endl;
            }
        }
    }

    return 0;
}