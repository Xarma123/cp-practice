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

    lol ans = 1;
    while (a != 1 && b != 1)
    {

        if (a < b)
        {
            ans += b / a;
            b %= a;
        }
        else
        {

            ans += a / b;
            a %= b;
        }
    }

    cout << ans + b - 1 + a - 1;

    return 0;
}