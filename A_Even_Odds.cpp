#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol od = n / 2;
    if (n % 2 != 0)
    {
        od++;
    }
    if (k <= od)
    {
        cout << 2 * 1ll * k - 1;
    }
    else
    {
        k -= od;
        cout << 2 * k;
    }

    return 0;
}