#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        for (lol i = 2; i < n; i++)
        {

            if (a[i - 1] > max(a[i], a[i - 2]) || a[i - 1] < min(a[i], a[i - 2]))
            {
                ans++;
            }
        }
        cout << 2 * n - 1 + ans << endl;
    }

    return 0;
}