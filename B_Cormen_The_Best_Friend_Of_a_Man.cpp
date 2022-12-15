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
    lol ans = 0;
    for (lol i = 1; i < n ; i++)
    {
        if (a[i] + a[i - 1] < k)
        {
            ans += k - a[i] - a[i - 1];
            a[i] += k - a[i] - a[i - 1];
        }
    }
    cout << ans << endl;
    for (lol i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}