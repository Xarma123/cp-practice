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
        lol mx = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        set<lol> q[n];
        for (lol i = 1; i * 1ll * i <= mx; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                if (a[j] < i * 1ll * i)
                {
                    
                }
            }
        }
    }

    return 0;
}