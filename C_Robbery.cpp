#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    lol a[n];
    lol x = LONG_LONG_MAX;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 0; i < n; i += 2)
    {
        x = min(x, a[i]);
    }
    if (n % 2 == 0)
        cout << 0;
    else
    {
       lol q= ceill(n/2.0);
       cout<<min((m/q)*1ll*k,x);

    }

    return 0;
}