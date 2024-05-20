#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m, k;
        cin >> n >> m >> k;
        if (k >= n - 1)
        {
            cout << "NO\n";
            continue;
        }

        // n-k > f
        lol f = n - k - 1;
        lol c = (n + f - 1) / f;
        if (c <= m)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }

    return 0;
}
