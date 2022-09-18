#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        for (lol i = n - 1; i >= 0; i--)
        {
            if (a[i] != a[n - 1])
            {
                ans++;
                lol c = n - (i + 1);
                while (c--)
                {
                    a[i] = a[n - 1];
                    i--;
                    if (i < 0)
                        break;
                }
                i++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}