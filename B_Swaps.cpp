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
        lol a[n], b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        unordered_map<lol, lol> x;
        lol j = 1;
        for (lol i = 0; i < n; i++)
        {
            while (j < b[i])
            {
                x[j] = i;
                j += 2;
            }
        }
        lol ans = INT_MAX;
        for (lol i = 0; i < n; i++)
        {
            ans = min(ans, (x[a[i]] + i));
        }
        cout << ans << endl;
    }

    return 0;
}