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
        lol a[n], b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        lol ans = 0;
        lol exp = 0;
        lol mxexp = 0;
        for (lol i = 0; i < n && i < k; i++)
        {
            exp += a[i];
            mxexp = max(mxexp, b[i]);
            ans = max(ans, exp + mxexp * 1ll * (k - i - 1));
        }
        cout << ans << '\n';
    }

    return 0;
}
