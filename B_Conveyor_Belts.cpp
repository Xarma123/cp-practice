#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, x, y, xs, ys;
        cin >> n >> x >> y >> xs >> ys;
        n /= 2;
        lol k = n - x;
        k = max(k, x - n - 1);
        k = max(k, y - n - 1);
        k = max(k, n - y);
        lol k2 = n - xs;
        k2 = max(k2, xs - n - 1);
        k2 = max(k2, ys - n - 1);
        k2 = max(k2, n - ys);
        cout << abs(k - k2) << '\n';
    }

    return 0;
}