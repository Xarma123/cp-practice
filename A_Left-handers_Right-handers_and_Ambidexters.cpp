#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol l, r, a;
    cin >> l >> r >> a;
    if (l > r)
        swap(l, r);
    if (r - l >= a)
    {
        l += a;
        a = 0;
    }
    else
    {
        a -= (r - l);
        l = r;
    }
    l += a / 2;
    r += a / 2;
    cout << 2ll * min(l, r);
    return 0;
}