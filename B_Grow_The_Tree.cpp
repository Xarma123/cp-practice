#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
    lol l = n / 2 + (n % 2);
    lol x = 0;
    for (lol i = n - 1; i >= n - l; i--)
    {
        x += a[i];
    }
    lol y = 0;
    for (lol i = n - l - 1; i >= 0; i--)
    {
        y += a[i];
    }
    cout << ((x * 1ll * x) + (y * 1ll * y));
}