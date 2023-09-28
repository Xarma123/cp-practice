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
        lol n, k, x;
        cin >> n >> k >> x;
        n = min(n, x);
        if (k > n)
        {
            cout << "NO\n";
            continue;
        }
        lol l = k * 1ll * (n + n - k + 1) / 2ll;
        lol m = k * 1ll * (1 + k) / 2ll;
        if (x >= m && x <= l)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}