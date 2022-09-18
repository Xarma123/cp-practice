#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    lol m;
    cin >> n >> m;
    lol v = (n) * (n + 1) / 2;
    v = m % v;
    lol x = floorl((long double)(sqrtl(1 + 8 * v) - 1) / 2);
    cout << v - (x * (x + 1) / 2);

    return 0;
}