#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol k[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> k[i];
        }
        sort(k, k + n);

        lol c[m];
        lol used[m];
        for (lol i = 0; i < m; i++)
        {
            used[i] = 1;
            cin >> c[i];
        }
        lol ans = 0;
        for (lol i = n - 1; i >= 0; i--)
        {
            lol j = upper_bound(used, used + k[i], 0) - used;
            if (j == k[i])
            {
                ans += c[k[i] - 1];
            }
            else
            {  
                ans += c[j];
                used[j] = 0;
            }
        }
        cout << ans << endl;
    }

    return 0;
}