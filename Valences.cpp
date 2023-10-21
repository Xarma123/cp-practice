#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        lol n;
        cin >> n;
        if (n == 0)
            break;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {

            if (2ll * i + 1 >= n)
                ans += a[i];
        }
        cout << ans << '\n';
    }

    return 0;
}
