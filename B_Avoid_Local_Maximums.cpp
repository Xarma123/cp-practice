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
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 1; i < n - 1; i++)
        {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                ans++;
                if (i + 3 < n)
                {
                    if (a[i + 2] > a[i + 1] && a[i + 2] > a[i + 3])
                        a[i + 1] = max(a[i], a[i + 2]);
                    else
                        a[i + 1] = a[i];
                }
                else
                    a[i + 1] = a[i];
            }
        }
        cout << ans << endl;
        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}