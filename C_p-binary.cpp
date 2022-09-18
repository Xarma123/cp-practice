#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, p;
    cin >> n >> p;
    lol ans = LONG_LONG_MAX;
    lol k = 1;
    while (n - k * 1ll * p >= k)
    {
        lol v = n - k * 1ll * p;
        lol V = v;
        lol c = 0;
        while (v > 0)
        {
            c++;
            v = v & (v - 1);
        }

        if (c <= k && k <= V)
        { 
            ans=k;
            break;
        }

        k++;
    }
    if (ans == LONG_LONG_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}