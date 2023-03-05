#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    if (a >= b / cbrt(3))
        cout << a;
    else
        cout << fixed << setprecision(10) << sqrtl(a * 1ll * a + powl(2ll * b - a * 1ll * cbrt(3ll), 2));

    return 0;
}
