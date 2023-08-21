#include <bits/stdc++.h>
using namespace std;
#define lol long long
/*
 1 2 3 4
 1 2 3 4
 1 2 3 4
 1 2 3 4

*/
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
        lol ans = 0;
        for (lol i = n; i > 1; i -= 2)
        {
            ans += (((n + 1) / 2) - (((n - i) / 2) + 1)) * 1ll * ((i * 1ll * i) - ((i - 2) * 1ll * (i - 2)));
        }

        cout << ans << '\n';
    }
}