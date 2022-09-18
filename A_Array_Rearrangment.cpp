#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, x;
        cin >> n >> x;
        lol a[n];
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        lol i;
        for (i = 0; i < n; i++)
        {
            lol f = x - a[i];
            lol q = LONG_LONG_MIN;
            for (lol j = 0; j < n; j++)
            {
                if (b[j] <= f)
                {
                    q = max(q, b[j]);
                }
            }
            for (lol j = 0; j < n; j++)
            {
                if (b[j] == q)
                {
                    b[j] = LONG_LONG_MAX;
                    break;
                }
            }
            if (q == LONG_LONG_MIN)
                break;
        }
        if (i == n)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}