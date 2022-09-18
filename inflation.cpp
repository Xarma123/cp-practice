#include <bits/stdc++.h>
#define lol long double
using namespace std;
int main()
{

    lol t;
    cin >> t;
    while (t--)
    {
        long n, k;
        cin >> n >> k;
        lol a[n], c[n];

        queue<long long> x;
        for (long i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i == 0)
                c[i] = a[i];
            else
            {
                c[i] = c[i - 1] + a[i];
                if ((a[i] * (100.0))  > ((k)*(c[i - 1] * (1.0))  ))
                {
                    x.push(i);
                }
            }
        }
        long long ans = 0;
        while (!x.empty())
        {
            long long i = x.front();
            if (a[i] * (100.0)  > (k)*(c[i - 1] * (1.0) + ans) * (1.0) )
            {
                ans += ceil((a[i]*(100) / (k)) - (c[i - 1] + ans));
            }

            x.pop();
        }
        cout << ans << endl;
    }

    return 0;
}