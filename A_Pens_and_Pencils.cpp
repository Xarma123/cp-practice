#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        lol x = ceill(a / (long double)c);
        lol y = ceill(b / (long double)d);
        if (x + y > k)
            cout << -1 << '\n';
        else
            cout << x << " " << y << '\n';
    }
}