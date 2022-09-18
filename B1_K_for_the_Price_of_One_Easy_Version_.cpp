#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n, p, k;
        cin >> n >> p >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol pre[n + 1];
        pre[0] = 0;
        for (lol i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] + a[i - 1];
        }
        lol ans = 0;

        for (lol i = 0; i < k; i++)
        {

            lol c = p;
            if (pre[i] > p)
            {
                break;
            }
            else
            {
                lol g = i;
                c -= pre[i];
                for (lol j = i - 1 + k; j < n; j += k)
                {
                    if (a[j] > c)
                        break;
                    else
                    {
                        g += k;
                        c -= a[j];
                    }
                }
                ans = max(ans, g);
            }
        } 
        cout<<ans<<endl;
    }

    return 0;
}