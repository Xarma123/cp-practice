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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool used[n];
        memset(used, false, sizeof(used));
        lol g = 0;
        lol ans[n];
        for (lol i = 0; i < n; i++)
        {
            lol j, mx = 0;
            for (lol k = 0; k < n; k++)
            {
                if (!used[k])
                {
                    if (__gcd(g, a[k]) > mx)
                    {
                        mx = __gcd(g, a[k]);
                        j = k;
                    }
                }
            }
            ans[i] = a[j];
            g = __gcd(g, a[j]);
            used[j] = true;
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}