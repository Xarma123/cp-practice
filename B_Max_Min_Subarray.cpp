#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol mx = LONG_LONG_MIN;
    while (n--)
    {
        lol t;
        cin >> t;
        mx = max(mx, t);
    }
    mx = 1ll * mx * mx;
    cout << mx << endl;

    return 0;
}