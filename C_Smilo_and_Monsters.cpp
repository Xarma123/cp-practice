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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol ans = 0;
        lol j = n - 1;
        lol s = 0;
        for (lol i = 0; i < n && i <= j; i++)
        {

            if (i == j)
            {
                lol x = (a[i] - s) / 2ll;
                ans += x;
                s += x;
                a[i] -= x;
                if (s)
                    ans++;
                a[i] -= s;
                ans += a[i];
            }
            else if (s + a[i] < a[j])
            {

                ans += a[i];
                s += a[i];
                a[i] = 0;
            }
            else
            {
                lol v = a[j] - s;
                ans += v;
                a[i] -= v;
                s += v;
                ans++;
                a[(j--)] = 0;
                s = 0;
                i--;
            }
            // cout << a[i] << " " << ans << " " << j << endl;
        }
        cout << ans << '\n';
    }

    return 0;
}
