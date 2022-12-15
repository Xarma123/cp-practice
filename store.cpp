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
        lol l[n], r[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i == 0)
                l[i] = a[i];
            else
            {
                l[i] = (l[i - 1] | a[i]);
            }
        }
        for (lol i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
                r[i] = a[i];
            else
                r[i] = (r[i + 1] | a[i]);
        }
        lol ans = -1;
        for (lol i = 0; i < n - 1; i++)
        {
            if (r[i] == l[i + 1])
            {
                
            }
        }
    }

    return 0;
}