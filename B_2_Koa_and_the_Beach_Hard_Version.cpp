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
        lol n, k, l;
        cin >> n >> k >> l;
        lol d[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        bool ans = true;
        lol l = k;
        lol r = k;
        for (lol i = 0; i < n && ans; i++)
        {
            if (l == k)
            {
                lol x = l - d[i];
                if (x < 0)
                    ans = false;
                x = min(x, k);
                l = x;
                r = x;
            }
            else if (l == 0)
            {
                // 1-1 
                
            }
            else
            {
                // 0 to (l+1)

                // r-1 - 1
            }
        }
    }
}