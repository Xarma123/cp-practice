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
        lol x = (sqrtl(1 + 8ll * n) - 1ll) / 2ll;
        if ((x * 1ll * (x + 1) / 2ll) == n)
        {
            cout << x + 1 << '\n';
        }
        else
        {
            cout << x + 1 + n - (x * 1ll * (x + 1) / 2ll) << '\n';
        }
    }
}