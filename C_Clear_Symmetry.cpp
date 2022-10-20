#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol x;
    cin >> x;
    if (x == 1)
        cout << 1;
    else if (x == 2)
        cout << 3;
    else if (x == 3)
        cout << 5;
    else
        cout << 2 * 1ll * ceill((sqrtl(2 * 1ll * (x - 1)) + 1) / 2.0) - 1;

    return 0;
}