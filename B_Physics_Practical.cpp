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
    lol c[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    sort(c, c + n);
    lol ans = LONG_LONG_MAX;
    for (lol i = 0; i < n; i++)
    {
        lol j = upper_bound(c, c + n, 2 * c[i]) - c;
        j--;
        ans = min(ans, n - 1 - j + i);
    }
    cout << ans;

    return 0;
}