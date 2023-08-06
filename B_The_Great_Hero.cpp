#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol A, B, n;
        cin >> A >> B >> n;
        lol a[n];
        lol mx = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        lol b[n];
        lol tot = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            lol k = ceill(b[i] / (long double)A);
          
            tot += k * 1ll * a[i];
        }
        tot -= mx;
        if (B > tot)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}