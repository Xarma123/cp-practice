#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m;
    cin >> n >> m;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    lol ps[n + 1];
    ps[0] = 0;
    for (lol i = 1; i <= n; i++)
    {
        ps[i] = ps[i - 1] + a[i - 1];
    }
    lol ans[n];
    for (lol k = 1; k <= n; k++)
    {
        lol j = k - m;
        lol i = k;
        lol v = 0;

        if (j <= 0)
        {
            v += (ps[i] - ps[0]);
        }
        else
        {
            v += ps[i];
            v += ans[j - 1];
        }

        ans[k - 1] = v;
    }
    for (lol i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}