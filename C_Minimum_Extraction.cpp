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
        lol s = 0;
        sort(a, a + n);
        lol j = INT_MAX;
        lol ans = a[0];
        for (lol i = 0; i < n - 1; i++)
        {
            if (a[i] <= 0)
            {
                for (lol j = i + 1; j < n; j++)
                {
                    a[j] -= a[i];
                    if (j == i + 1)
                        ans = a[j];
                }
            }
            else
            {
                ans = max(ans, a[i + 1] - a[i]);
            }
        } 
        cout<<ans<<endl;
    }

    return 0;
}