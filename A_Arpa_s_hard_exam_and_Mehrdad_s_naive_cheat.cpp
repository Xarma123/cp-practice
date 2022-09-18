#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol v = 1378;
    lol m = 10;
    lol r = 1;
    while (n > 0)
    {
        if (n % 2 != 0)
        {
            r = (r * 1ll * v) % m;
        }
        n = n >> 1;
        v = (v * 1ll * v) % m;
    }
    cout << r;

    return 0;
}