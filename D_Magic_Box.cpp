#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol x, y, z, x1, y1, z1;
    lol a1, a2, a3, a4, a5, a6;
    cin >> x >> y >> z >> x1 >> y1 >> z1;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    int ans = 0;
    if (y < 0)
        ans += a1;
    if (y > y1)
        ans += a2;
    if (z < 0)
        ans += a3;
    if (z > z1)
        ans += a4;
    if (x < 0)
        ans += a5;
    if (x > x1)
        ans += a6;
    cout << ans << endl;

    return 0;
}