#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    lol b[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (lol i = 0; i < n; i++)
    {
        b[i] = a[i] - b[i];
    }
    sort(b, b + n);
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        if (b[i] <= 0)
        {

            lol it = lower_bound(b, b + n, 1 - b[i]) - b;
            ans += n - it;
        }
        else
        {
            ans += n - (i + 1);
        }
    }
    cout << ans << endl;
    return 0;
}