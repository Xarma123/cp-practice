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
        lol a, b, n;
        cin >> a >> b >> n;
        lol x[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> x[i];
        }

        lol ans = b - 1;
        for (lol i = 0; i < n; i++)
        {
            ans += min(x[i] + 1, a) - 1;
        }
        cout << ans + 1 << '\n';
    }
}