#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol ans = 0, z = 1;
        while (k)
        {
            if (k & 1)
            {
                ans = (ans + z) % (long long)(1e9 + 7);
            }
            k = k >> 1;

            z = (z * n) % (long long)(1e9 + 7);
        }
        cout << ans << endl;
    }

    return 0;
}