#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, A;
    cin >> n >> A;
    lol a[n];
    lol s = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    for (lol i = 0; i < n; i++)
    {
        lol mx = A - (n - 1);
        s -= a[i];
        lol mn = max(A - s, 0ll);
        s += a[i];
        mn = max(mn, 1ll);
        mx = min(mx, a[i]);
        cout << a[i] - (mx - mn + 1) << " ";
    }

    return 0;
}