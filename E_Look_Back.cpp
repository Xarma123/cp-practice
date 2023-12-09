#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << log2l((1 / (long double)3)) << endl;

    lol t;
    cin >> t;
    while (t--)
    {

        lol n;
        cin >> n;
        lol a[n];
        lol c[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            c[i] = 0;
            while (a[i] % 2 == 0)
            {
                c[i]++;
                a[i] /= 2ll;
            }
        }

        lol ans = 0;
        for (lol i = 1; i < n; i++)
        {
            lol x;
            x = max((long long)ceill(log2l(a[i - 1] / (long double)a[i])) + c[i - 1], 0ll);

            if (x > c[i])
            {
                ans += x - c[i];
                c[i] = x;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
