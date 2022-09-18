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
    lol lcm = a * 1ll * b / __gcd(a, b);
    lol A = 0, B = 0;
    for (lol i = a; i < lcm; i += a)
    {
        A++;
    }
    for (lol i = b; i < lcm; i += b)
    {
        B++;
    }
    if (A < B)
        A++;
    else
        B++;
    if (A > B)
        cout << "Dasha";
    else if (A < B)
        cout << "Masha";
    else
        cout << "Equal";

    return 0;
}