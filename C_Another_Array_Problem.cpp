#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
            cin >> a[i];
        if (n >= 4)
        {
            lol mx = 0;
            for (lol i = 0; i < n; i++)
            {
                if (a[i] > mx)
                    mx = a[i];
            }
            cout << mx * 1ll * n << endl;
        }
        else if (n == 2)
        {
            cout << max(a[0] + a[1], abs(a[0] - a[1]) * 2ll) << endl;
        }
        else
        {
            cout << max(a[0] + a[1] + a[2],
             max(n * 1ll * a[0],
             max(n * 1ll * a[2], 
             max(abs(a[0] - a[1]) * 3ll, 
             max(abs(a[0] - a[2]) * 3ll, abs(a[1] - a[2]) * 3ll)))))<< endl;
        }
    }

    return 0;
}