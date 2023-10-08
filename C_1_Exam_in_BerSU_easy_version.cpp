#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol f[101];
    memset(f, 0, sizeof(f));
    for (lol i = 0; i < n; i++)
    {
        lol r = m - a[i];
        lol pass = 0;
        for (lol j = 1; j <= 100; j++)
        {
            if (f[j] * 1ll * j <= r)
            {
                pass += f[j];
                r -= f[j] * 1ll * j;
            }
            else
            {
                pass += r / j;
                r -= (r / j) * 1ll * j;
            }
        }
        cout << i - pass << " ";
        f[a[i]]++;
    }
}