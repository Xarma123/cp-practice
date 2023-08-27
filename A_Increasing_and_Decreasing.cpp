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
        lol x, y, n;
        cin >> x >> y >> n;
        // x         y-1-2-3  y-1-2  y-1 y
        lol a[n];
        a[0] = x;
        a[n - 1] = y;
        for (lol i = n - 2; i > 0; i--)
        {
            a[i] = a[i + 1] - (n - i) + 1;
        }
        if (a[1] - a[0] > a[2] - a[1])
        {
            for (lol i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << '\n';
        }
        else
            cout << -1 << '\n';
    }
}