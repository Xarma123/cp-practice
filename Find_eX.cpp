#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol lcm(lol a, lol b)
{
    return a * 1ll * b / __gcd(a, b);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, c, d;
        cin >> a >> b >> c >> d;
        if (((a + 1) % b) == ((c + 1) % d))
            cout << 1 << '\n';
        else
        {

            cout << lcm(b, d) - min(b, d) + 1 << '\n';
        }
    }

    return 0;
}