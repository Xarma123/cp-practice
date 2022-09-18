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
    lol neg = 0;
    while (neg < n && a[neg] < 0)
        neg++;
    if (k <= neg)
    {
        lol i = 0;
        while (k--)
        {
            a[i] *= -1;
            i++;
        }
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            ans += a[i];
        }
        cout << ans;
    }
    else
    {
        for (lol i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                k--;
                a[i] *= -1;
            }
        }
        sort(a, a + n);
        if (k % 2)
            a[0] *= -1;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            ans += a[i];
        }
        cout << ans;
    }

    return 0;
}