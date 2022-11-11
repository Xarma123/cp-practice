#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    lol c[n + 1];
    c[0] = 0;
    for (lol i = 0; i < n; i++)
    {
        c[i + 1] = a[i] + c[i];
    }
    lol ans = -1;
    lol no;
    for (lol i = 0; i < n; i++)
    {
        lol st = -1, e = i;
        while (st != e - 1)
        {
            lol m = (st + e) / 2;
            if (m == -1)
                st = m;
            else if (m == i)
                e = m;
            else
            {
                if (a[i] * 1ll * (i - m + 1) - c[i + 1] + c[m] <= k)
                    e = m;
                else
                    st = m;
            }
        }
        if (ans < i - e + 1)
        {
            ans = i - e + 1;
            no = a[i];
        }
    }
    cout << ans << " " << no;

    return 0;
}