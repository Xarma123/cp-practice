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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        lol ex = 0;
        for (lol i = 0; i < n - 1; i++)
        {
            if (a[i + 1] >= a[i])
            {
                ans += a[i + 1] - a[i];
                ex += a[i]-a[i+1];
            }
            else
            {
                ans += a[i] - a[i + 1];
            }
        }
        ans+=abs(a[n - 1] + ex);
        cout << ans << endl;
    }

    return 0;
}