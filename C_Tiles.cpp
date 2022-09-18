#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol w, h;
    cin >> w >> h;
    lol ans = 1;
    while (w--)
        ans = (2 * ans) % (998244353);
    while (h--)
        ans = (2 * ans) % (998244353);
    cout << ans;

    return 0;
}