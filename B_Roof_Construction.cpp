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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            a[i] = i;
        }
        lol mx = 0;
        lol i;
        for (i = 60; i >= 0; i--)
        {
            if ((n - 1) & (1 << i))
            {
                break;
            }
        }
        for (lol j = n - 1; j >= 0; j--)
        {
            if (!((j & (1 << i))))
            {
                if (j - 1 >= 0)
                {
                    swap(a[0], a[j]);
                }
                break;
            }
        }

        for (lol i = 0; i < n; i++)
        {
            if (i < n - 1)
            {
                mx = max(mx, a[i] ^ a[i + 1]);
            }
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}