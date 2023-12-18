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
        for (lol i = 1; i < n; i++)
        {
            lol c = 0;
            while (a[i] != a[0])
            {
                c++;
                a[i] = (a[i] + a[0]) / 2ll;
            }
            ans = max(ans, c);
        }

        cout << ans << '\n';
        if (ans <= n)
        {
            for (lol i = 0; i < ans; i++)
            {
                cout << a[0] << ' ';
            }
        }
        if (ans)
            cout << '\n';
    }

    return 0;
}
