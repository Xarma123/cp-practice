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

    lol s = 0;
    for (lol i = 1; i < n; i++)
    {
        s += a[i];
    }
    if (a[n - 1] * 1ll * (n - 1) - s >= a[0])
    {
        cout << a[n - 1];
    }
    else
    {
        lol ex = a[0] - (a[n - 1] * 1ll * (n - 1) - s);
        cout << ex / (n - 1) + ((ex % (n - 1))>0) + a[n - 1];
    }

    return 0;
}