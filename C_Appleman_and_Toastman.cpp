#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    lol ans = 0;
    lol s = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += a[i];
        s += a[i];
    }
    sort(a, a + n);
    for (lol i = 1; i < n; i++)
    {
        s -= a[i - 1];
        ans += s;
        ans += a[i - 1];
    }
    cout << ans;

    return 0;
}