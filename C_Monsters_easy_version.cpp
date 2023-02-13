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
        sort(a, a + n);
        lol c = 0;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] > c)
            {
                ans += (a[i] - (c + 1));
                c++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}