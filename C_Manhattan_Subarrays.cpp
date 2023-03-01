#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        for (lol i = 2; i < n; i++)
        {

            if (a[i - 1] > max(a[i], a[i - 2]) || a[i - 1] < min(a[i], a[i - 2]))
            {
                ans++;
            }
        }
        for (lol i = 3; i < n; i++)
        {
            bool f = true;
            for (lol j = i - 3; j < i - 1; j++)
            {
                for (lol k = j + 1; k < i; k++)
                {
                    for (lol q = k + 1; q <= i; q++)
                    {
                        if (!(a[k] > max(a[j], a[q]) || a[k] < min(a[j], a[q])))
                            f = false;
                    }
                }
            }
            if (f)
                ans++;
        }

        cout << ans + 2ll * n - 1 << endl;
    }

    return 0;
}