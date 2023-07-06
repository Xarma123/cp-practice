#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol p[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        lol c[k + 1];
        for (lol i = 0; i <= k; i++)
        {
            c[i] = 1;
        }

        for (lol i = 0; i < k; i++)
        {
            if (p[i] <= k)
                c[p[i]]--;
        }
        lol ans = 0;
        for (lol i = 0; i < k; i++)
        {
            ans += c[i + 1];
        }
        cout << ans << '\n';
    }
}