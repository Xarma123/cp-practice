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
    lol d = 0;
    lol t = 0;
    for (lol i = 0; i < n; i++)
    {
        if (d - a[i] * 1ll * (t)*1ll * (n - i - 1) >= k)
        {
            d += a[i] * 1ll * (t);
            t++;
        }
        else
        {
            cout << i + 1 << '\n';
        }
    }

    return 0;
}