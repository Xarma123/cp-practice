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
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    lol ans = 0;
    for (lol i = n - 2; i >= 0; i--)
    {
        a[i] = a[i] + a[i + 1];
    }
    lol take = 1;
    lol N = n;
    while (n)
    {
        ans += a[N - take];
        take *= 4;
        n /= 4;
    }
    cout << ans;

    return 0;
}