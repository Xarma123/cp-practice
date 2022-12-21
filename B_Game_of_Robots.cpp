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
    lol st = -1, e = n + 1;
    while (st != e - 1)
    {
        lol m = (st + e) / 2;
        if ((m * 1ll * (m + 1) / 2) < k)
        {
            st = m;
        }
        else
            e = m;
    }
    k -= (st * 1ll * (st + 1) / 2);
    cout << a[k - 1];

    return 0;
}