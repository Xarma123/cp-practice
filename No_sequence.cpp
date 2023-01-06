#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
int main()
{
    int tes;
    cin >> tes;
lable:
    while (tes-- > 0)
    {
        long long n, k, s, i, tmp, sum = 0;
        cin >> n >> k >> s;
        tmp = s;
        int b[n];
        for (i = 0; i < n; i++)
        {
            long long rem = s % k;
            if (rem != 0 && rem != 1 && rem != k - 1)
            {
                cout << -2 << endl;
                // break;
                goto lable;
            }
            if (rem == k - 1 && k != 2)
                rem = -1;
            b[i] = rem;
            // cout<<b[i]<<" ";
            s = (s - rem) / k;
        }
        for (i = 0; i < n; i++)
            sum += (b[i] * binpow(k, i));
        if (sum != tmp)
        {
            cout << -2 << endl;
            goto lable;
        }
        for (i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << endl;
    }
    return 0;
}
