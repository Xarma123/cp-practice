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
        lol n, k, q;
        cin >> n >> k >> q;
        lol a[k + 1];
        for (lol i = 1; i <= k; i++)
        {
            cin >> a[i];
        }
        lol b[k + 1];
        for (lol i = 1; i <= k; i++)
        {
            cin >> b[i];
        }
        a[0] = b[0] = 0;
        while (q--)
        {
            lol d;
            cin >> d;
            lol i = upper_bound(a, a + k + 1, d) - a;
            i--;
            if (i == k)
            {
                cout << b[i] << ' ';
            }
            else if (a[i] == d)
            {
                cout << b[i] << " ";
            }
            else
            {
                cout << (long long)floorl((((long double)(d - a[i]) * (long double)(b[i + 1] - b[i])) /((long double)(a[i + 1] - a[i])))) + b[i] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
