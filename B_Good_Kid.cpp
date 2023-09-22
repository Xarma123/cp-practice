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
        lol mx = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {

            if (a[mx] > a[i])
                mx = i;
        }
        a[mx]++;
        lol ans = 1;
        for (lol i = 0; i < n; i++)
        {
            ans = ans * 1ll * a[i];
        }
        cout << ans << '\n';
    }
}