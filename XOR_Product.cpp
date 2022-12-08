#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
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
        lol i = 0;
        lol j = n - 1;
        while (i < j)
        {
            if (a[i] != 1)
                break;
            while (j >= 0 && a[j] % 2 != 0)
            {
                j--;
            }
            if (j < 0)
                break;
            a[j]++;
            j--;
            i++;
        }
        lol ans = 1;
        lol m = 998244353;
        for (lol i = 0; i < n; i++)
        {
            ans = (ans * 1ll * a[i]) % m;
        }
        cout << ans << endl;
    }

    return 0;
}