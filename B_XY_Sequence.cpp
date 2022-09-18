#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, B, x, y;
        cin >> n >> B >> x >> y;
        lol v = 0;
        lol ans = 0;
        for (lol i = 1; i < n + 1; i++)
        {
            if (v + x <= B)
            {
                v += x;
            }
            else
                v -= y;

            ans += v;
        }
        cout << ans << endl;
    }

    return 0;
}