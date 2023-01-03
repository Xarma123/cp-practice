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
    lol tot = (1ll << n) - 1;
    lol c = n;
    while (k != tot / 2 + 1)
    {
        if (k > tot / 2)
        {
            k -= tot / 2 + 1;
        }
        tot = tot / 2;
        -c--;
    }
    cout << c;

    return 0;
}