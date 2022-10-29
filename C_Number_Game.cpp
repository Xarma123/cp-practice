#include <bits/stdc++.h>
#define lol long long
using namespace std;
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
        sort(a, a + n);
        lol b[n];
        for (lol k = n; k >= 0; k--)
        {
            lol K = k;
            for (lol i = 0; i < n; i++)
            {
                b[i] = a[i];
            }

            while (K)
            {
                lol i = upper_bound(b, b + n, K) - b;
                i--;

                if (i >= 0)
                {
                    if (b[i] == LONG_LONG_MIN)
                        break;
                    b[i] = LONG_LONG_MIN;
                }
                else
                    break;
                i = 0;
                while (i < n && b[i] == LONG_LONG_MIN)
                    i++;
                if (i != n)
                {
                    b[i] += K;
                }
                K--;
                sort(b, b + n);
            }
            if (K == 0)
            {
                cout << k << endl;
                break;
            }
        }
    }

    return 0;
}