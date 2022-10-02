#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol sgn(lol a)
{
    if (a > 0)
        return 1;
    else
        return -1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol x1, y1;
    cin >> x1 >> y1;
    lol x2, y2;
    cin >> x2 >> y2;
    lol n;
    cin >> n;
    lol ans = 0;
    while (n--)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        if (sgn(a * 1ll * x1 + b * 1ll * y1 + c) != sgn(a * 1ll * x2 + b * 1ll * y2 + c))
            ans++;
    }
    cout << ans;

    return 0;
}