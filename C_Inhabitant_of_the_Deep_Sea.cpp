#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol i = 0, j = n - 1;
        lol ans = 0;
        while (i < j)
        {
            if (a[i] <= a[j])
            {
                if (k >= a[i] * 2ll - 1)
                {
                    ans++;
                    k -= 2ll * a[i] - 1;
                    a[j] -= a[i] - 1;
                    i++;
                    if (k)
                        a[j]--, k--;
                    if (a[j] == 0)
                    {
                        ans++;
                        j--;
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (k >= a[j] * 2ll)
                {
                    ans++;
                    k -= a[j] * 2ll;
                    a[i] -= a[j];
                    j--;
                }
                else
                {
                    break;
                }
            }
        }
        if (i == j)
        {
            if (a[i] <= k)
                ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}
