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
    lol b[n];
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += a[i] / 10;

        if (a[i] % 10 == 0)
            b[i] = 0;
        else
            b[i] = 10 - a[i] % 10;
    }
    sort(b, b + n);
    lol c = 0;
    for (lol i = 0; i < n; i++)
    {
        if (k >= b[i])
        {
           
            k -= b[i];
            if (b[i])
                ans++;
            if (a[i] % 10 == 0)
                b[i] = 0;
            else
                b[i] = 10 - a[i] % 10;
            a[i] += b[i];
            c += (100 - a[i]) / 10;
        }
    }
   

    ans += min(k / 10, c);

    cout << ans;

    return 0;
}