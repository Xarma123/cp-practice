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
    lol mx = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    lol g = 0;
    for (lol i = 0; i < n; i++)
    {
        g = __gcd(g, mx - a[i]);
    }
    lol c = 0;
    for (lol i = 0; i < n; i++)
    {
        c += (mx - a[i]) / g;
    }
    cout << c << " " << g;
}