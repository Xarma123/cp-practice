#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, x;
    cin >> n >> x;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        ans += x * 1l * a[i];
        x = max(1ll, x - 1);
    }
    cout << ans;

    return 0;
}