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
    lol si = 0, sum = 0, e = 0, ans = 0;
    while (e != n)
    {
        sum += a[e];
        if (sum <= s)
        {
            ans = max(ans, e - si + 1);
        }
        else
        {
            while (sum > s)
            {
                sum -= a[si];
                si++;
            }
            ans = max(ans, e - si + 1);
        }

        e++;
    }
    cout<<ans;

    return 0;
}