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
    if (a < b)
        swap(a, b);
    lol t = 7 - a;
    lol v = __gcd(6ll, t);
    cout << t / v << "/" << 6 / v;

    return 0;
}