#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol h;
        for (h = 63; h >= 0; h--)
        {
            if ((n & (1ll << h)))
                break;
        }
        if (h + 1 > k)
        {
            cout << (1ll << k) << '\n';
        }
        else
        {
            cout << n + 1 << '\n';
        }
    }
}