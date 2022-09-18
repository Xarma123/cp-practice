#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, r;
        cin >> n >> r;
        lol ans = 0;
        if (n <= r)
        {
            ans += 1;

            r = n - 1;
        }
        ans += r * (r + 1) / 2;

        cout << ans << endl;
    }

    return 0;
}