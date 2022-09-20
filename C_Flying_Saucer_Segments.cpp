#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol r = 1;
    lol a = 3;
    while (n > 0)
    {
        if (n % 2 != 0)
            r = (r * 1ll * a) % m;
        a = (a * 1ll * a) % m;
        n /= 2;
    }
    cout << (r - 1 + m) % m;

    return 0;
}