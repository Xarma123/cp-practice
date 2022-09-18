#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol k;
    cin >> k;
    while (k--)
    {
        lol n, x, t;
        cin >> n >> x >> t;
        lol ans = 0;
        if (x > t)
        {
            cout << ans << endl;
        }
        else
        {
            if (t / x >= n - 1)
            {
                cout << (n) * (n - 1) / 2 << endl;
            }
            else
            {
                cout << (t / x) * (n - (t / x)) + n * (n - 1) / 2 - (n * (n - (t / x)) - (n - (t / x)) * ((n - (t / x)) + 1) / 2) << endl;
            }
        }
    }

    return 0;
}