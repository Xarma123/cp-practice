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
        for (lol i = 0; i < n - 1; i++)
        {
            cin >> a[i];
        }
        a[n - 1] = 0;
        lol b[n];
        b[0] = a[0] + 1;
        for (lol i = 1; i < n; i++)
        {
            lol k = max(0ll, ((a[i] - a[i - 1]) / (b[i - 1])) + 1);
            b[i] = b[i - 1] * 1ll * k + a[i - 1];
        }
        for (lol i = 0; i < n; i++)
        {
            cout << b[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
