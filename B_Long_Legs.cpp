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

        lol a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        lol ans = a + b;
        for (lol i = 2; i <= 1e5; i++)
        {
            lol v = a / i + (a % i > 0);
            v += b / i + (b % i > 0);
            ans = min(ans, v + i - 1);
        }
        cout << ans << '\n';
    }

    return 0;
}