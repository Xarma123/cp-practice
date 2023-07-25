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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol ans = 1;
        lol l = -1;
        for (lol i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] <= k)
            {
                ans = max(ans, i - l);
            }
            else
            {
                l = i - 1;
            }
        }
        cout << n - ans << '\n';
    }
}