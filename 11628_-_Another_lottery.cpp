#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        lol sum = 0;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m - 1; j++)
            {
                lol t;
                cin >> t;
            }
            cin >> a[i];
            sum += a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            lol g = __gcd(a[i], sum);
            cout << a[i] / g << " / " << sum / g << endl;
        }
    }

    return 0;
}