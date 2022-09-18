#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, s;
    cin >> n >> s;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol si = 0, sum = 0, e = 0, ans = INT_MAX;
    while (e != n)
    {
        sum += a[e];
        if (sum >= s)
        {
            ans = min(ans, e - si + 1);
            while (sum >= s)
            {
                ans = min(ans, e - si + 1);
                sum -= a[si];

                si++;
            }
        }

        e++;
    }
    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}