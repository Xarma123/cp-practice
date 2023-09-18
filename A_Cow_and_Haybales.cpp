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
        lol n, d;
        cin >> n >> d;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 1; i < n; i++)
        {
            if (i * 1ll * a[i] <= d)
            {
                d -= i * 1ll * a[i];
                a[0] += a[i];
            }
            else
            {
                a[0] += d / i;
                d = 0;
            }
        }
        cout << a[0] << '\n';
    }
}