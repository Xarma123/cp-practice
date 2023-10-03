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
        lol a, b, c;
        cin >> a >> b >> c;
        lol mx = c / 2;
        lol ans = 0;
        if (b < mx)
        {
            ans += b * 3ll;
            b = 0;
        }
        else
        {
            ans += mx * 3ll;
            b -= mx;
        }
        b /= 2;
        if (b > a)
        {
            ans += a * 3ll;
        }
        else
        {
            ans += b * 3ll;
        }
        cout << ans << '\n';
    }
}