#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    lol n;
    cin >> n;
    lol k;
    cin >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        if (a[i] < k)
        {
            ans += a[i];
        }
        else if (a[i] >= 3 * k)
        {
            ans += a[i] - 3 * k;
        }
        else if (a[i] >= 2 * k)
        {
            ans += a[i] - 2 * k;
        }
        else
        {
            ans += a[i] - k;
        }
    }
    cout << ans;
    return 0;
}