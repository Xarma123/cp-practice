#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol a[n];
        lol sum = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum <= k)
        {
            cout << 0 << endl;
        }
        else
        {
            lol ans = 0;
            sort(a, a + n);
            while (a[0] * n > k)
            {
                ans++;
                a[0]--;

                sum--;
            }

            if (sum <= k)
                cout << ans << endl;
            else
            {
                if (a[0] == 0)
                {
                    ans++;
                    a[0]--;
                }
                for (lol i = n - 1; i >= 0; i--)
                {
                  
                    sum = sum - (a[i] - a[0]);
                    if (a[i] != a[0])
                        ans++;
                    if (sum <= k)
                        break;
                }
                cout << ans << endl;
            }
        }
    }

    return 0;
}